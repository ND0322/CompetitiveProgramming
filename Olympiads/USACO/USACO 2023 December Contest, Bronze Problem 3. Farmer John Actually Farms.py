from math import ceil

for _ in range(int(input())):
    #i hate this question
    n = int(input())

    h = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))
    t = list(map(int,input().split(" ")))

    order = [i for i in range(n)]

    order.sort(key = lambda x : t[x])

    ans = 0

    for balls in range(n-1):
        i = order[balls]
        j = order[balls+1]

        #if this line wont alway be higher

        if h[i] < h[j] and a[i] > a[j]:
            ans = max(ans, (int)(ceil((h[j]-h[i]+1)/(a[i]-a[j]))))
        

    for i in range(n):
        h[i] += ans * a[i]

    flag = True

    for balls in range(n-1):
        i = order[balls]
        j = order[balls+1]
        if(h[i] <= h[j]):
            flag = False

    if flag:
        print(ans)
    else:
        print("-1")
    

