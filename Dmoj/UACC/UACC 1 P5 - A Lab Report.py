def f(x):
    a = 0
    b = 0

    for i in range(n-1):
        d = l[i+1]-l[i]

        if(d>x):
            b += d-x
        if(d < x):
            a += x-d

    return a+b - min(a,b)

n = int(input())

l = list(map(int,input().split(" ")))

lo = -10**18
hi = 10**18
ans = 0

while(lo <= hi):
    mid = (lo+hi)//2

    if(f(mid) < f(mid+1)):
        ans = mid
        hi = mid-1
    else:
        lo = mid+1

print(f(ans))