n, k= map(int,input().split(" "))

ans = 0

for i in list(map(int,input().split(" "))):
    if(i <= k):
        ans += i
        
print(ans)