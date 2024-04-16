def can(x):
    if(s[:x] != s[n-x:]):
        return False

    return s[:x] in s[1:n-1]

s = input()
n = len(s)


"""

lo = 0
hi = n
ans = 0

while(lo <= hi):
    mid = (lo+hi)>>1

    if(can(mid)):
        ans = mid
        lo = mid+1
    else:
        hi = mid-1

if(ans):
    print(s[:ans])
else:
    print ("Just a legend")





"""
