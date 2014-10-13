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


# # scrape each popular destination page and all subpages to get sub-page links 
# output = File.open( "sub_dest_links.txt", "w" )
# input = File::open("dest_links.txt", "r")
# input.each do |dest|
#     output << dest
#     url = dest.chomp[0..-2]
#     # Check for sub-pages and output URLs if present
#     pg_links = Nokogiri::HTML(open(url)).css("div.div4 > a")
#     pg_links[0..-2].each do |l|
#         output << url + "#{l}"[/#[1-9][0-9]?/] + ",\n"
#     end
#     sleep 1.0 + rand
#     puts "Scraped: #{url}"
# end
# input.close
# output.close


# # Scrape the top-level page into output to get all route links for all destinations
# output = File.open( "route_links.txt", "w" )
# input = File::open("sub_dest_links.txt", "r")
# input.each do |dest|
#     url = dest.chomp[0..-2]
#     Nokogiri::HTML(open(url)).css("td:nth-child(1) > a").each do |l|   
#         route_link = base_url + "#{l}"[/\/farehistory\/.*\.html/] + ",\n"
#         output << route_link
#     end
#     puts "Scraped: #{url}"
# end
# input.close
# output.close

## Post processing of route data to ensure clean/unique links
# push route links data into a set to ensure no duplicate links
input = File.open( "route_links.txt", "r" )
unique_routes = Set.new
input.each do |link|
    unique_routes << link
end
input.close
puts "Adding route links to file..."
# write unique links in set out to a new file
output = File.open( "route_links_clean.txt", "w" )
unique_routes.each do |link|
    output << link
end
output.close
puts "Cleaning of route links is complete!"
