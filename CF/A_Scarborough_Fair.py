n,m = map(int,input().split(" "))

s = input()

a = [0]

for c in s:
    a.append(c)

for i in range(m):
    l,r,c1,c2 = map(str, input().split(" "))
    l = int(l)
    r = int(r)

    for j in range(l, r+1):
        if(a[j] == c1):
            a[j] = c2

print("".join(a[1:]))

