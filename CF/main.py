a = list(map(int,input().split(" ")))
b = list(map(int,input().split(" ")))


cnt = 0

for i in range(len(a)):
    for j in range(len(a)):
        sm = 0
        for k in range(i, j+1):
            sm += a[i]
            sm -= b[i]
        
        if(sm == 0):
            cnt += 1
print(cnt)