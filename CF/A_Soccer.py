
    


for _ in range(int(input())):
    x1,y1 = map(int,input().split(" "))
    x2, y2 = map(int,input().split(" "))

    if x1 == x2 and y1 == y2:
        print("YES")
    elif x1 == x2:
        print("YES") if not (min(y1, y2) <= x1 <= max(y1, y2)) else print("NO")
    elif y1 == y2:
        print("YES") if not (min(x1, x2) <= y1 <= max(x1, x2)) else print("NO")
    else:
        print("NO")


