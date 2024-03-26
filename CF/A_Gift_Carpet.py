for _ in range(int(input())):
    n,m = map(int,input().split(" "))

    grid = []

    dp = [[False] * 5] * m
    a = [[False] * 4] * m

   