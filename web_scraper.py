# Written by: Kevin Keller
# Creation date: Nov 02, 2013
# Last modified date: Nov 03, 2013
# Gets a webpage, given by the user, and returns a CSV file of Japanese sentences.

# import need modules
from bs4 import BeautifulSoup
import urllib, re, os, csv

def get_user_url(): # function to get the url input from the user
  target_url = raw_input()
  return target_url

def grab_and_parse_results(target_url): # function to get HTML from a url and parse into sentences
  # Grabs the HTML from the given url address
  html_soup = BeautifulSoup(urllib.urlopen(target_url))
  # Pull out only the lines that match the pattern given by the regualar expression below
  # Results should contain only Japanese sentences (Look for any Japanese characters that end with . ! ? ...)
  pattern = u'[\u3030-\u9FAF][\u3030-\u9FAF0-9A-Za-z\u3001\u2026 ]+[\u300D|\u3002|\uFF01|\uFF1F|\u2026]+'
  # Returns a list based on a set of unique sentences only (removes duplicates)
  return list(set(re.findall(pattern, html_soup.decode('utf8'))))

def save_as_csv(sentence_list): # function to handle creation, writing, and closing of CSV file
  # Create a new CSV file to write sentences to
  csv_output_file = open('web_scraper_file.csv', 'w')
  # Create the csv writer object
  file_writer = csv.writer(csv_output_file)
  # Write each sentence scraped as a new row in the CSV file
  file_writer.writerow("Expression") # Write in header label for first row
  for sentence in sentence_list:
    file_writer.writerow(sentence.encode('utf8'))
  # Close out the CSV file when finished writing to it
  csv_output_file.close()

# RUN TIME CODE:
#target_url = get_user_url() # Get target url from the user
target_url = 'http://rkmg.higu.biz/?a=alche&m=1&story_idx=22&list_idx=531'
sentences = grab_and_parse_results(target_url) # Grab and parse HTML into sentences
save_as_csv(sentences)
