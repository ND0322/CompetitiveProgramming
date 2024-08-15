for _ in range(int(input())):
    n = int(input())

    if(not (n&1)):
        print(n//2,n//2)
        continue

    if(n == 9):
        print(4,5)
        continue
    

    if(not (str(n)[-1] == '9' and int(str(n)[-2]) & 1)):
        print(n//2 + 1, n//2)
        continue
    
    #19 19 
    
    print(n//2 + 5, n//2 - 4)
    

        