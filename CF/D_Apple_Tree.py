import sys

sys.setrecursionlimit(10**6)


def dfs(node,par):

    if len(adj[node]) == 1 and node != 1:
        dp[node] = 1
        return
    
    dp[node] = 0
    for child in adj[node]:
        if(child == par):
            continue
        dfs(child,node)

        dp[node] += dp[child]
    
    


    

for _ in range(int(input())):
    n = int(input())

    adj = [[] for i in range(n+1)]

    for i in range(n-1):
        x,y = map(int,input().split(" "))


        adj[x].append(y)
        adj[y].append(x)

    dp = [1] * (n+1)

    dfs(1,-1)

    for i in range(int(input())):
        x,y = map(int,input().split(" "))
        print(dp[x] * dp[y])



    