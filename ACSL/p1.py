#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'findDiscardSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER originalRows
#  2. STRING tiles
#

def findDiscardSum(originalRows, tiles):
    
    last = []
    
    for i in str(originalRows):
        last.append(i)
    
    cur = 0
    tiles = tiles.split(" ")
    ans = 0
    
    i = 0
    while(i < len(tiles)):

        flag = False
        for j in range(4):
            if(last[(cur+j)%4] == tiles[i][0]):
                last[(cur+j)%4] = tiles[i][1]
                if(tiles[i][0] == tiles[i][1] and i != len(tiles)-1):
                    i+=1
                    while(i < len(tiles)):
                        if(last[(cur+j)%4] == tiles[i][0]):
                            last[(cur+j)%4] = tiles[i][1]
                            break
                        if(last[(cur+j)%4] == tiles[i][1]):
                            last[(cur+j)%4] = tiles[i][0]
                            break
                        ans += int(tiles[i][0]) +int(tiles[i][1])
                        i+=1
                cur = (cur+j+1)%4
                flag = True
                break

            if(last[(cur+j)%4] == tiles[i][1]):
                last[(cur+j)%4] = tiles[i][0]
                if(tiles[i][0] == tiles[i][1] and i != len(tiles)-1):
                    i+=1
                    while(i < len(tiles)):
                        if(last[(cur+j)%4] == tiles[i][1]):
                            last[(cur+j)%4] = tiles[i][0]
                            break
                        ans += int(tiles[i][0]) +int(tiles[i][1])
                        i+=1
                cur = (cur+j+1)%4
                flag = True
                break
                        
                   
        if(not flag):
            ans += int(tiles[i][0]) + int(tiles[i][1])
        i+=1
            
    return ans
        
        
        
    
x = int(input())
y = input()

print(findDiscardSum(x,y))