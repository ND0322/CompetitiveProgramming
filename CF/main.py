n = int(input())

a = list(map(int,input().split(" ")))


cnt = 0

for i in range(n):
    for j in range(i, n):
        x = 0
        for k in range(i, j+1):
            x ^= a[k]

        if(x == 0):
            cnt += 1

print(n-cnt)