# Written by: Kevin Keller
# Creation date: Nov 02, 2013
# Last modified date: Nov 22, 2013
# Gets a webpage, given by the user, and returns a TXT file of unique Japanese sentences.

# import need modules
from bs4 import BeautifulSoup
import urllib
import re

def get_user_url(): # function to get the url input from the user
  target_url = raw_input()
  if target_url == "":
    raise TypeError("Input cannot be an empty string.")
  return target_url

'''
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
# prints out each of the sentences to a file
with open('ja_output.txt', mode='r', encoding='utf-8') as f:
  f.write('JAPANESE SENTENCES FROM URL: {}'.format(target_url))
  for sentence in list_of_sentences:
    f.write(sentence)
'''
