n = int(input())

s = input()

flag = True

for i in range(n-1):
    if(s[i] == "a" and s[i+1] == "b"):
        print("Yes")
        flag = False
        break
    if(s[i] == "b" and s[i+1] == "a"):
        print("Yes")
        flag = False
        break

if(flag):
    print("No")