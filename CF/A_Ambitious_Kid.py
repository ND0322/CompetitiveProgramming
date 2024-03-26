n = int(input())

l = list(map(int,input().split(" ")))

ans = 1e9

for i in l:
    ans = min(ans, abs(i))
print(ans)