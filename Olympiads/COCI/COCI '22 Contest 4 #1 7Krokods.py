def calc(a,b,c,d):
   return a * a + b*b + c * c + d * d + 7 * min(a//2, b, c//2, d)


n,m = map(int,input().split(" "))

s = input()

l = [0,0,0,0]

balls = {"k" : 0, "r" : 1, "o" : 2, "d" : 3}

for i in s:
    l[balls[i]] += 1

ans = calc(l[0], l[1], l[2], l[3])

for i in range(m+1):
    for j in range(m+1):
        for k in range(m+1):
            for h in range(m+1):
                if(i + j + k + h > m):
                    break

                ans = max(ans, calc(l[0]+i, l[1] + j, l[2] + k, l[3] + h))
print(ans)
