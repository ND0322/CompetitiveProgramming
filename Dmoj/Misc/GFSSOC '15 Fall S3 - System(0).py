n = int(input())



f = input().split("e")
s = input().split("e")
print(float(f[1]))
a = 10**(int(f[1])-int(s[1]))
ans = -(1/n) * float(f[0]) / float(s[0]) * a

print(ans)