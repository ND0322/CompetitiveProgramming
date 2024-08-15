def solve(l):
    if(len(l) == 1):
        if(l[0] == 24):
            return 1
        else:
            return 0
    for i in range(len(l)):
        for j in range(i+1,len(l)):
            nxt = []

            for k in range(len(l)):
                if(k == j or k == i):
                    continue

                nxt.append(l[k])
            
            nxt.append(l[i] + l[j])

            if(solve(nxt)):
                print(l,nxt, "+")
                return 1
            
            nxt.pop()

            nxt.append(l[i] * l[j])

            if(solve(nxt)):
                print(l,nxt, "*")
                return 1
            
            nxt.pop()

            nxt.append(l[i] - l[j])

            if(solve(nxt)):
                print(l,nxt,i,j, "-")
                return 1
            
            nxt.pop()

            nxt.append(l[j] - l[i])

            if(solve(nxt)):
                print(l,nxt, "-")
                return 1
            
            nxt.pop()

            if(l[j]):
                nxt.append(l[i] / l[j])

                if(solve(nxt)):
                    print(l,nxt, "/")
                    return 1
                
                nxt.pop()
            
            if(l[i]):
                nxt.append(l[j] / l[i])

                if(solve(nxt)):
                    print(l,nxt, "/")
                    return 1
                
                nxt.pop()

    return 0

solve([1,5,5,5])

    



    
