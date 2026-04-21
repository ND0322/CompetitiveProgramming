from math import ceil
from itertools import permutations

n = int(input())

sz  = list(map(int, input().split(" ")))

a,b,c = map(int,input().split(" "))

ans = 1e9

flag = 1

for p in permutations(sz):
    x = p[0]
    y = p[1]
    z = p[2]
    per = (a//x) * (b//y) * (c//z)

    flag &= per == 0
    if(per == 0):
        continue

    ans = min(ans, ceil(n/per))

if(flag):
    print("SCAMMED")
else:
    print(ans)
    
