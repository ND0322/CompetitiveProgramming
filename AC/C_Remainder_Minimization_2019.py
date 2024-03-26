def solve():

    l,r = map(int,input().split(" "))

    for i in range(1000000):
        x = 2019 * i

        if(l <= x and x <= r):
            print(0)
            return
    
    ans = 2018

    for i in range(l,r+1):
        for j in range(i+1, r+1):
            ans = min(ans, (i*j)%2019)
    
    print(ans)

solve()
