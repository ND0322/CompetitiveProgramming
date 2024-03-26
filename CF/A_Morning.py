for _ in range(int(input())):
    s = input()

    last = 1

    ans = 0
    for i in s:
        if(i == '0'):
            ans += 10-last
            last = 10
        else:
            ans += abs(int(i) - last)
            last = int(i)
    print(ans+4)