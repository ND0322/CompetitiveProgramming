from math import ceil

for _ in range(int(input())):
    a,b,c,d,f = map(int,input().split(" "))


    a += c * (b // d)
    b %= d

    if(a >= f):
        print(0)
        continue

    ans = d - b - 1

    print(ans)

    opt1 = f - a


    opt2 = d - (f-a) % c

    a += c

    print(f-a, opt2)

    
    opt2 += ceil((f-a) / c) * d

    print(opt1, opt2, ans)

    print(ans + max(opt1, opt2))