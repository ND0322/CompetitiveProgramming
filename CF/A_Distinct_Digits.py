a,b = map(int,input().split(" "))
flag = 0
for i in range(a, b+1):
    if len(set(str(i))) == len(str(i)):
        print(i)
        flag = 1
        break

if(not flag):
    print(-1)