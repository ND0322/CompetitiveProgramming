
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split(" ")))

    i = 0

    ans = set()

    while(i < n):
        sz = 0
        flag = True
        while(i < n and a[i] == 7):
            sz+=1
            ans.add(sz)
            i+=1
            flag = False
        
        else:
            i+=1

    print(len(ans))
        
