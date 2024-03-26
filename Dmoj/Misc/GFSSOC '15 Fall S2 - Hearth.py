n,t = map(int,input().split(" "))

a = []

for i in range(n):
    a.append(input().split(" "))
    a[-1][1] = int(a[-1][1])

ans = []

for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            if(a[i][1] + a[j][1] + a[k][1] <= t):
                ans.append((sorted([a[i][0], a[j][0], a[k][0]])))

ans.sort()

for i in ans:
    print(" ".join(i))