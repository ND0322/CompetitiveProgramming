a = input()
b = input()


f = abs(ord(a[0]) - ord(a[1]))
s = abs(ord(b[1]) - ord(b[0]))


if(f==s or f == 5-s):
    print("Yes")
else:
    print("No")