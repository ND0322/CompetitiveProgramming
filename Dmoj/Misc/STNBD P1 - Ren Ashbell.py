n = int(input())

flag = 1

me = int(input())

for i in range(n-1):
    flag &= me > int(input())
print(flag * "YES")
print((1-flag) * "NO")