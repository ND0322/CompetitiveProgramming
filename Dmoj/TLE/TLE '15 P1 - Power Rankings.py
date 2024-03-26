n,p = map(int,input().split(" "))

sums = []

for i in range(n):
    sums.append([0,""])




for i in range(n):
    sums[i][1] = input()
    
    


for i in range(p):
    a = list(map(int,input().split(" ")))

    for j in range(n):
        sums[j][0] += a[j]

sums.sort(key = lambda x:x[0],reverse=True)

for i in range(3,3+n):
    print(str(i) + ".", sums[i-3][1])