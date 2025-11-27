n = int(input())

b = []
for i in range(n):
    a = input()

    if(a == '2'):
        for j in range(len(b)):
            b[j] = b[j][1:] + [b[j][0]]
    else:
        y = int(a.split(" ")[1])

        l = [j for j in range(1,y+1)]
        b.append(l)

ans = []

for j in b:
    ans += j

print(" ".join(map(str, ans)))