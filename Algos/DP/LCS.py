n,m = map(int,input().split(" "))

a = list(map(int,input().split(" ")))
b = list(map(int,input().split(" ")))

dp = [[0] * (m+1) for i in range(n+1)]

for i in range(n-1,-1,-1):
    for j in range(m-1,-1,-1):
        if a[i] == b[j]:
            dp[i][j] = dp[i+1][j+1] + 1
        else:
            dp[i][j] = max(dp[i+1][j],dp[i][j+1])

print(dp[0][0])