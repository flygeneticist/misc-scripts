# Written by: Kevin Keller
# Creation date: Nov 02, 2013
# Last modified date: Nov 03, 2013
# Gets a webpage, given by the user, and returns a CSV file of Japanese sentences.

# import need modules
from bs4 import BeautifulSoup
import urllib, re, sys

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
  return list(set(re.findall(pattern, html_soup.decode('utf-8-sig'))))

# RUN TIME CODE:
target_url = get_user_url() # Get target url from the user
list_of_sentences = grab_and_parse_results(target_url) # Grab and parse HTML into sentences
# prints out each of the sentences to the terminal output
for sentence in list_of_sentences:
  print sentence
