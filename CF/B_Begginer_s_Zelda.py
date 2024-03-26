for _ in range(int(input())):

    n = int(input())

    deg = [0] * (n+1)

    for i in range(n-1):
        x,y = map(int,input().split(" "))

        deg[x]+=1
        deg[y]+=1

    ans = 0

    for i in range(1,n+1):
        if deg[i] == 1:
            ans+=1
    #print(ans)
    print((ans+1)//2)

