for _ in range(int(input())):
    n = int(input())

    t = input()

    i = 0

    ans = ""
    while i < n:

        c = t[i]
        i+=1
        while(t[i] != c):
            i+=1
        i+=1
        ans += c
    print(ans)

  