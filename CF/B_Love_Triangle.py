for _ in range(int(input())):
    n,k = map(int,input().split(" "))

    if(n > 2):
        print(n*k//3)
    else:
        print(0)