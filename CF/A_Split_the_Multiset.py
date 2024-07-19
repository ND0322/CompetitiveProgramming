import math
for _ in range(int(input())):
    a,b = map(int,input().split(" "))

    print(math.ceil((a-1)/(b-1)))
