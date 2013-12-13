import re
from collections import defaultdict

processed_data = defaultdict(int) # dict to capture reduced dataset info, default value == 0
only_chars = re.compile('\D+').search # pre-compiled reg-exp, for fast run time, to get street name, ignoring numbers

# import raw data file with parking information
with open('Parking_data.csv', 'r') as raw_data:
    # skip the first line of header data
    next
    # iterate over the remaining file line by line
    for line in raw_data:
        # split line by ',' into an array
        worked_line = line.split(',')
        # get and clean up street name for dict use and, if valid name found, collect fine amount in dict
        try:
            processed_data[only_chars(worked_line[7]).group(0).lstrip()] += int(worked_line[4])
        except:
            next

# find street with greatest total fines processed_data
highest_street = max(processed_data, key=processed_data.get)
highest_fine = processed_data[highest_street]

# print out the results
print('Highest revenue street: {0} with ${1}.'.format(highest_street, highest_fine))
