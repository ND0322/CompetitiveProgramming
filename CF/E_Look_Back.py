import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split(" ")))

    ans = 0
    last = 0
   

    for i in range(1,n):
        

        last = max(0, math.ceil(math.log2(a[i-1]/a[i])+last))
        ans += last
    print(ans)