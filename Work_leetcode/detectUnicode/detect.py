__author__ = 'lichen'
import matplotlib.pyplot as plt
import numpy as np

input = open('input.txt')
output = open('output.txt','w')

data = []

# Read in data
for line in input.readlines():
    line = line.strip('\n')
    data.append(line)


print(len(data))


# Ouput data

# check illegal character
for line in data:
    s = str(line)
    if s.find('。') != -1 or s.find('“') != -1 or s.find('”') != -1 or s.find('，') != -1:
        print ("illegal exists")

totalCounts = 0
lineCounts = 0
wordCounts = 0
for line in data:
    s = str(line)
    lineCounts += 1
    for ch in s:
        totalCounts += 1

        if totalCounts == 512147:
            print 
            break

print(lineCounts)



#for i in line:
#    output.write(i)
#    output.write('\n')

#output.close()

print('s write success')

print('Program terminates')
