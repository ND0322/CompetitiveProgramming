n,m = map(int,input().split(" "))

#n * m even they will each take half

if(not ((n*m) & 1)):
    print(n*m//2, n*m//2)
else:
    if(n == 1 and m == 1):
        print(1,0)
    else:
        print((n*m + min(n,m))//2, (n*m - min(n,m))//2)

