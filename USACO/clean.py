import os

for i in os.listdir('.'):
    j = i.replace('Jan', 'JAN')
    j = j.replace('Feb', 'FEB')
    j = j.replace('Dec', 'DEC')
    j = j.replace('_0', '0')
    print(i + ' -> ' + j)
    # os.rename(i, j)