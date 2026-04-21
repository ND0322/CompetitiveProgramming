import math

for _ in range(int(input())):
    n,a,b,c = map(int, input().split(" "))

    if(n * a < c):
        print(-1)
    else:
        print(math.ceil((c + b * n) / (a+b)))