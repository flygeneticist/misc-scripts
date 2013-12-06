#!/usr/bin/python3
import sys

def reducer():
  salesTotal = 0
  salesCounter = 0
  oldKey = None

  for line in sys.stdin:
      data = line.strip().split("\t")

      if len(data) != 2:
        # Something has gone wrong. Skip this line.
        continue


      salesCounter += 1
      salesTotal += float(thisSale)

  if oldKey != None:
    salesCounter += 1
    salesTotal += float(thisSale)
    print ("Total # of sales: {0}".format(salesCounter))
    print ("Total sales amount: {1:.2f}".format(salesTotal))


def main():
  import io
  reducer()


main()
