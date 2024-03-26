import math
for _ in range(int(input())):
    n = int(input())

    s = sum(list(map(int,input().split(" "))))

    if(math.sqrt(s).is_integer()):
        print("YES")
    else:
        print("NO")
