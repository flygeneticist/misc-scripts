# Written by: Kevin Keller
# Creation date: Nov 02, 2013
# Last modified date: Nov 27, 2013
# Gets a webpage, given by the user, and returns a TXT file of unique Japanese sentences.

# import need modules
from bs4 import BeautifulSoup
import urllib
import re


# function to get the url input from the user
def get_user_url():
  target_url = input("Enter the URL to scrape: ")
  if target_url == "":
    raise ValueError("Input cannot be an empty string.")
  return target_url.strip()


# function to get HTML from a url and parse into sentences
def grab_and_parse_results(target_url):
  http_response = urllib.request.urlopen(target_url)
  html_soup = BeautifulSoup(http_response) # Grab the HTML from the given url address
  # Pull out only the lines that match the pattern given by the regualar expression below
  pattern = u'[\u3030-\u9FAF][\u3030-\u9FAF0-9A-Za-z\u3001\u2026 ]+[\u300D|\u3002|\uFF01|\uFF1F|\u2026]+'
  # Return a list based on a set of unique sentences only (removes duplicates)
  return list(re.findall(pattern, html_soup.decode('utf-8-sig')))


# function to run scrapper and output results
def run_scraper():
  sentences = grab_and_parse_results(get_user_url()) # Get target url, grab and parse HTML into sentences
  # print out each of the sentences to a file
  with open('ja_output.txt','w') as f:
    for sentence in sentences:
      print(sentence + '\n', f)


if __name__ == '__main__':
  run_scraper()
