from math import ceil

n = int(input())

s = input().split("0")

day = n

if(len(s[0])):
    day = len(s[0])
if(len(s[len(s)-1])):
    day = min(day,len(s[len(s)-1]))




for i in range(1, len(s)-1):
    if(len(s[i])):
        day = min(day, ceil(len(s[i])/2))

ans = 0

#print(s)
#print(day)
for i in s:
    ans += ceil(len(i)/(2*(day-1)+1))
print(ans)

