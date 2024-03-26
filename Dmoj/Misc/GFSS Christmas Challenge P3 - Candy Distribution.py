n,k = map(int,input().split(" "))

a = []

for i in range(n):
    a.append(int(input()))

a.sort()

ans = 0

for i in a:
    if(k < i):
        break

    ans += 1
    k -= i

print(ans)