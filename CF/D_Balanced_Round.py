for _ in range(int(input())):
    n,k = map(int,input().split(" "))

    a = list(map(int,input().split(" ")))

    bad = []
    #bad.append(-1)

    

    a.sort()

    flag = True

    for i in range(n-1):
        if a[i+1] - a[i] > k:
            bad.append(i)
            flag = False

    #print(a)
    

   #print(bad)

    if flag:
        print(0)
        continue



    ans = 1e9

    #print(a)
    #print(bad)
   
    
    for i in range(len(bad)-1):
        ans = min(ans,n-(bad[i+1]-bad[i]))
        #print(bad[i] + 1 + (n - bad[i+1]))
    

    
    if(len(bad) > 1):
        ans = min(ans,bad[-1]+1,n-bad[0]-1)
    
    
    elif(len(bad) == 1):
        ans = min(ans,n-bad[0]-1,bad[0]+1)
    print(ans)