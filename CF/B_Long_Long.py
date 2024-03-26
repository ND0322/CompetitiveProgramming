for _ in range(int(input())):
    n = int(input())

    arr = list(map(int,input().split(" ")))

    groups = []

    i = 0

    while i < n:

        if(arr[i] <= 0):
            add = []

            for j in range(i,n):
                if(arr[j] <= 0):
                    add.append(arr[j])
                else:
                    i = j+1
                    break
                if(j == n-1):
                    i = j+1
                    break
            
            groups.append(add)
        
        else:
            i += 1
    
    ans = 0
    for i in groups:
        for j in i:
            if j < 0:
                ans += 1
                break

    s = 0

    for i in arr:
        s += abs(i)

    print(s,ans)       

    
                
