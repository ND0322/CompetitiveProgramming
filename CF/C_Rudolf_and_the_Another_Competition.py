for _ in range(int(input())):
    n,m,h = map(int,input().split(" "))

    ans = []

    for i in range(n):
        times = list(map(int,input().split(" ")))

        times.sort()

        pen = 0
        p = 0
        t = 0

        for j in times:
            if t + j > h:
                break
            
            p += 1
            t += j
            pen += t
        
        ans.append((-p,pen,i))
    

    ans.sort()

    for i in range(n):
        if ans[i][2] == 0:
            print(i+1)
    

        