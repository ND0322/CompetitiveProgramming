for _ in range(int(input())):
    n,k = map(int,input().split(" "))
    ans = [0] * n
    a = list(map(int,input().split(" ")))
    b = list(map(int,input().split(" ")))

    d = {}

    for i in range(n):
        d[i] = a[i]


    
    d = (sorted(d.items(),key = lambda x:x[1]))
    b.sort()





    for i in range(n):

        ans[d[i][0]] = b[i]
    
    
    p = ""

    for i in ans:
        p += str(i) + " "
    
    print(p.strip())
        

