def solve():
    n = int(input())

    x,y = map(int,input().split(" "))

    

    for i in range(n-1):
        a,b = map(int,input().split(" "))

        if(a >= x and b >= y):
            print("-1")
            return
    
    
    print(x)
for _ in range(int(input())):
    solve()