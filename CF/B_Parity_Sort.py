def solve():
    n = int(input())

    m = {}

    a = list(map(int,input().split(" ")))

    for i in range(n):
        m[i] = a[i]
    
    m = sorted(m.items(),key = lambda x:x[1])



    for i in range(n):
        if(m[i][1]%2 != a[i]%2):
            print("NO")
            return
    print("YES")


for _ in range(int(input())):
    solve()

