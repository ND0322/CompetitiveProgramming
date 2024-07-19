n = int(input())
ans = [0] * 10

i = 1

while(i <= n):
    for d in range(10):

        hi = n//(i * 10)
        cur = (n//i) % 10
        lo = n % i

        cnt = hi * i
        if(not d):
            cnt -= i
        
        if(d < cur):
            cnt += i
        if(d == cur):
            cnt += lo + 1
        ans[d] += cnt
    i *= 10

print(" ".join(list(map(str,ans))))
