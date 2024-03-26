import math
n,d = map(int,input().split(" "))


ans = 0

a = []

for i in range(n):
    a.append(list(map(int,input().split(" "))))

for i in range(n):
    for j in range(i+1,n):
        sum = 0

        for k in range(d):
            sum += abs(a[i][k] - a[j][k])**2
        
        if(math.sqrt(sum).is_integer()):
            ans+=1

print(ans)