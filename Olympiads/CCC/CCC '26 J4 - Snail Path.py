n = int(input())


s = set()

s.add((0,0))

cur = [0,0]
ans = 0

for i in range(n):
    x = input()

    dir = x[:1]

    st = int(x[1:])

    for step in range(1, st+1):

        if(dir == 'N'):
            cur[1] += 1
        if(dir == 'S'):
            cur[1] -= 1

        if(dir == 'E'):
            cur[0] -= 1
        if(dir == 'W'):
            cur[0] += 1

        if(tuple(cur) in s):
            ans += 1
        s.add(tuple(cur))

print(ans)

    



