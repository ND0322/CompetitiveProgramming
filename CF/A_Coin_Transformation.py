import math


for _ in range(int(input())):
    n = int(input())

    if n <= 3:
        print(1)
        continue

    k = math.floor(math.log(n / 3) / 2) 
    print(2 ** k)

