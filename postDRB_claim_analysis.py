# Post -Filing DRB Claim Statistical Analysis
# Created on: November 15, 2013
# Modified on: February 11, 2014

# script to work over the prepped post-DRB claim files for statistical analysis looking
# at lines submitted vs lines dropped by broker prior to filing.

def process_claim(sends_file, claimed_file, x):
    # load the lists preped for the target claim month
    claimed_list = []
    with open(claimed_file, 'r') as claim:
        for line in claim:
            claimed_list.append(str(line))
    
    sends_list = []
    with open(sends_file, 'r') as sent:
        for line in sent:
            sends_list.append(str(line))

    # generate unclaimed list
    unclaimed_list = [e for e in sends_list if (e not in claimed_list)]

    # print lines in unclaimed list generated by script to an output_file
    out_file = 'U:\out_file' + x + '.txt'
    with open(out_file, 'w') as out:
            for i in unclaimed_list:
                out.write(i)

    # print out details of final lists to screen
    print "Claim Month " + str(sends_file)[3:-10]
    print "Sends:" + str(len(sends_list)) + " lines."
    print "Claimed:" + str(len(claimed_list)) + " lines."
    print "Unclaimed:" + str(len(unclaimed_list)) + " lines."
    print ""

# run time code
process_claim('U:\January10_SENDS.txt','U:\January10_CLAIMED.txt', 'January10')
process_claim('U:\February10_SENDS.txt','U:\February10_CLAIMED.txt', 'February10')
process_claim('U:\March10_SENDS.txt','U:\March10_CLAIMED.txt', 'March10')
process_claim('U:\April10_SENDS.txt','U:\April10_CLAIMED.txt', 'April10')
process_claim('U:\May10_SENDS.txt','U:\May10_CLAIMED.txt', 'May10')
process_claim('U:\June10_SENDS.txt','U:\June10_CLAIMED.txt', 'June10')
process_claim('U:\July10_SENDS.txt','U:\July10_CLAIMED.txt', 'July10')
process_claim('U:\January11_SENDS.txt','U:\January11_CLAIMED.txt', 'January11')
process_claim('U:\February11_SENDS.txt','U:\February11_CLAIMED.txt', 'February11')
process_claim('U:\March11_SENDS.txt','U:\March11_CLAIMED.txt', 'March11')

hold = input("> ")