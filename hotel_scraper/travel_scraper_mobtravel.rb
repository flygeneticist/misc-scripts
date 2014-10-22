require 'nokogiri'
require 'open-uri'
require 'json'

# require 'pry'

base_url = "http://www.travelmob.com/vacation-rentals"
ctry = {"vietnam" => 26,"cambodia" => 7,"thailand" => 125}

## grab all broad links to popular destinations
results = []
ctry.each do |k,v|
    (1..v).each do |pg|
        url = "#{base_url}/#{k}?page=#{pg.to_s}"
        Nokogiri::HTML(open(url)).css(".space.row").each do |box|
            name = box.css('h4').text
            city = box.css('[itemprop="addressRegion"]').text
            price = box.css('.price').text
            bedrooms = box.css('.bedrooms').text
            capacity = box.css('.accommodates').text

            num_bedrooms = bedrooms.match /(\d+)/
            num_capacity = capacity.match /(\d+)/
            country = k.capitalize
            city_name = city.gsub(", #{country}", "")

            results << {
                "country" => country,
                "city" => city_name,
                "name" => name,
                "price" => price.to_i,
                "bedrooms" => num_bedrooms[1].to_i,
                "capacity" => num_capacity[1].to_i
            }

        end
        puts "I just scraped the F%!@* out of #{k} - pg #{pg}"
        sleep 1.0 + rand # sleep to avoid hitting the server too frequently
    end
end

output = File::open("travelmob_data.txt", "w")
output << results.to_json
output.close
puts "Done! ^____^ "
