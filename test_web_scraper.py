# unit tests for web_scraper.py
import unittest
import web_scraper

class GrabAndParse_Tests(unittest.TestCase):

  def test_for_blank_user_input(self):
    self.assertRaises(ValueError, web_scraper.get_user_input, '')

