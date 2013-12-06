#!/usr/bin/python3
import sys, re

def mapper():
  path_re = '/(\w|-|/)*(?:\.\D\D\D|\.\D\D) '

  for line in sys.stdin:

    try:
      print (re.search(path_re, line).group(0))
    except:
      continue # go to next line

def main():
  import io
  mapper()
  sys.stdin = sys.__stdin__

main()
