for _ in range(int(input())):
    n = input()

    ans = 0

    for i in n:
        ans = max(ans, int(i))
    print(ans)