from math import lcm
for _ in range(int(input())):
    a,b,c = map(int,input().split(" "))

    ans = 2
    tmp = lcm(a,b)
    c += tmp

    ans += c//a - tmp//a
    ans += c//b - tmp//b

    print(ans)



