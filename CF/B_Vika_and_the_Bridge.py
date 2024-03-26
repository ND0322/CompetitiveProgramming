#find the color with the smallest max gap between, and the ans will be distance max(distance for other, gap//2)

for _ in range(int(input())):
    n,k = map(int,input().split(" "))

    gaps = [[] for i in range(k+1)]
    last = [-1] * (k+1)

    arr = list(map(int,input().split(" ")))

    for i in range(n):
        if len(gaps[arr[i]]) == 0:
            gaps[arr[i]].append(i)
            
        else:
            gaps[arr[i]].append(i - last[arr[i]] - 1)
            

        last[arr[i]] = i

    
    ans = 1e9

    for i in range(1,k+1):
        gaps[i].append(n - last[i] - 1)

        gaps[i].append(max(gaps[i])//2)
        gaps[i].remove(max(gaps[i]))

        ans = min(ans,max(gaps[i]))
    
  
    print(ans)
   
