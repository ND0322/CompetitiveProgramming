def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))

    a.sort()

    target = a[0]%2

    cnt = [[0] * n, [0] * n]

   

    for i in range(n):
        if i == 0:
            cnt[0][i] = int(a[i] % 2)
            cnt[1][i] = int(not (a[i] % 2))
        else:
            cnt[0][i] = cnt[0][i-1] + a[i]%2
            cnt[1][i] = cnt[1][i-1] + (not (a[i] % 2))
    
  
    
    for i in range(1,n):
        if a[i] % 2 == target:

            continue

        if target:

            if cnt[0][i-1] > 0:
                continue

            print("NO")
            return
        else:
            if cnt[0][i-1] > 0:
                continue
        
            print("NO")

            return
        
    print("YES")

for _ in range(int(input())):
   solve()

        


