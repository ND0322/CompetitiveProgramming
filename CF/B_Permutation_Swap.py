t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    max_distance = 1
    for i in range(n):
        if p[i] != i+1:
            j = p.index(i+1)
            distance = abs(i-j)
            max_distance = min(max_distance, distance)
    print(max_distance)