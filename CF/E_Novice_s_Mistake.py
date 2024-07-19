for _ in range(int(input())):
    n = int(input())


    ans = []

    #length
    if(n < 10):
        for i in range(1,7):
            t = int(str(n) * i)
            for j in range(1,10001):
                b = j*len(str(n)) - i
            
                if n * j - b == t:
                    ans.append((j,b))
    elif (n < 100):
        for i in range(1,14):

            t = ""

            for j in range(i):
                t += str(n)[j&1]

            t = int(t)

            for j in range(1,10001):
                
                b = j*len(str(n)) - i
            
                if n * j - b == t:
                    ans.append((j,b))
    
    
    
    print(max(len(ans)-1,0))

    for i in range(1,len(ans)):
        print(ans[i][0], ans[i][1])
            

        


        
    