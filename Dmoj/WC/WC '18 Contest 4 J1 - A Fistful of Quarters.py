import math
d = int(input())

d *= 100

q = int(input())

q *= 25

print(max(0,math.ceil((d-q)/25)))