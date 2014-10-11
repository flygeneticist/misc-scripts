require 'nokogiri'
require 'open-uri'

base_url = "http://http://www.faredetective.com"

## grab all broad links to popular destinations
# output = File::open("dest_links.txt", "w")
# ("A".."Z").each do |alpha|
#     url = "#{base_url}/farehistory/flights-index-#{alpha}.html"
#     Nokogiri::HTML(open(url)).css("td:nth-child(1) > a").each do |l|   
#         output << base_url + "#{l}"[/\/farehistory\/.*\.html/] + ",\n"
#     end
# end
# output.close

# scrape each popular destination page and all subpages to get links for specific routes
output = File.open( "route_links.txt", "w" )
input = File::open("dest_links_test.txt", "r")
input.each do |dest|
    # Scrape the first top-level page into output
    url = dest.chomp[0..-2]
    Nokogiri::HTML(open(url)).css("td:nth-child(1) > a").each do |l|   
       output << base_url + "#{l}"[/\/farehistory\/.*\.html/] + ",\n"
    end

    # Check for sub-pages and crawl if present
    pg_links = Nokogiri::HTML(open(url)).css("div.div4 > a")
    if pg_links.length >= 2
        pg_links[0..-2].each do |sl|
            subpg = url + "#{sl}"[/#[1-9][0-9]?/]
            Nokogiri::HTML(open(subpg)).css("td:nth-child(1) > a").each do |subl|
                puts subl  
                output << base_url + "#{subl}"[/\/farehistory\/.*\.html/] + ",\n"
            end
        end
    end
end
input.close
output.close