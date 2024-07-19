#only multiply with 1 and 0

for _ in range(int(input())):
    n = int(input())

    s = input()

    if(n == 2):
        print(int(s))
        continue


    ans = 1e9

    for i in range(n-1):
        l = []

        j = 0
        while(j < n):
            if(j == i):
                l.append(int(s[j] + s[j+1]))
                j += 1
            else:
                l.append(int(s[j]))
            j+=1

        sm = 0

        for i in l:
            if(i == 1):
                continue
            sm += i

        if(l == (n-1) * [1]):
            sm=1

        if(0 in l):
            sm = 0
        

        ans = min(ans, sm)

    print(ans)

        

        