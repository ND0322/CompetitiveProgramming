for _ in range(5):
    n = int(input())
    
    l = []
    
    for i in range(n):
        x = int(input())
        
        l.append(x)


        
    for i in range(1, n+2):
        if(i not in l):
            print(i)
            break