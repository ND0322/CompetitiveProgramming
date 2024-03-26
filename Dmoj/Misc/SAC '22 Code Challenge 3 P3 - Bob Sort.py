import math

n = int(input())

a = [([0,0]) for i in range(n)]

inp = input().split(" ")

mx = 0

for i in range(n):
    a[i][1] = inp[i]
    mx = max(mx, int(inp[i]))



for i in range(0, int(math.log10(mx)) + 1):
    for j in range(n):
        if(int(a[j][1]) < 10**i):
            a[j][0] = "0"
        else:
            a[j][0] = a[j][1][len(a[j][1])-i-1]

    #print(a)

    a = sorted(a, key = lambda x : x[0])
    ans = []
    for j in a:
        ans.append(j[1])

    print(" ".join(ans))

