

n = int(input())

slopes = set()
flag = False
for i in range(n):
    x,y = map(int,input().split(" "))

    if(x):
        slopes.add(y/x)
    else:
        flag &= not bool(y)

if(flag):
    print("no")
elif(len(slopes) <= 1):
    print("yes")
else:
    print("no")

#y = mx