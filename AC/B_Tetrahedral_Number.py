n = int(input())

for i in range(n+1):
    for j in range(n+1):
        for k in range(n+1):
            if(i + j + k > n):
                continue
            print(i,j,k)
        