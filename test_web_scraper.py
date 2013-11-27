# unit tests for web_scraper.py
import unittest
from unittest.mock import patch
import web_scraper

class GetUserUrlTests(unittest.TestCase):

  @patch('builtins.input', lambda: '')
  def test_for_blank_user_input(self):
    '''get_user_url should raise ValueError with blank string input'''
    self.assertRaises(ValueError, web_scraper.get_user_url)

  @patch('builtins.input', lambda: 'http://testurl.com/')
  def test_returns_string_user_url(self):
    '''get_user_url should return a string with valid string input'''
    self.assertTrue(isinstance(web_scraper.get_user_url(), str))

  @patch('builtins.input', lambda: 42)
  def test_for_nonstring_input(self):
    '''get_user_url should raise TypeError with non-string'''
    self.assertRaises(TypeError, web_scraper.get_user_url)


class GrabAndParseTests(unittest.TestCase):

"""
  def test_known_input_returns_text_object(self):
    '''When given valid, known URL input, should return a text object'''
    self.assertTrue(web_scraper.grab_and_parse_results, target_url)
"""

if __name__ == '__main__':
    unittest.main()
