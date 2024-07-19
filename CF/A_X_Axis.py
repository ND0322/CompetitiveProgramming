for _ in range(int(input())):
    a = sorted(list(map(int,input().split(" "))))

    print(a[1] - a[0] + a[2] - a[1])
