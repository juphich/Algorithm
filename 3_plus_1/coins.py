#coins.py

import sys

readl = lambda:sys.stdin.readline()
testCases = int(readl())

countDic = {}

def count(money, coins):
    if money == 0 :
        return 1
    if money < 0 :
        return 0
    if (
            

for i in range(testCases):
    money = int(readl().strip().split()[0])
    coins = []

    for coin in readl().strip().split():
        coins.append(int(coin))
    
    coins.sort()
    count(money, tuple(coins))
