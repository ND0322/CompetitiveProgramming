for _ in range(int(input())):
    n = int(input())

    i = 0

    s = input()

    blocks = []

    while(i < n):
        c = s[i]
        sz = 0
        while(i < n and s[i] == c):
            i+=1
            sz += 1
        
        blocks.append((c,sz))

        
    ans = 0
    for i in range(len(blocks)):
        ans = max(ans, blocks[i][1])

        if(blocks[i][1] == 1):
            res = 0
            c = -1
            if(i != 0):
                res += blocks[i-1][1]
                c = blocks[i-1][0]
                ans = max(ans, max(blocks[i][1],blocks[i-1][1]) + 1)
            
            if(i != len(blocks)-1):
                ans = max(ans, max(blocks[i][1], blocks[i+1][1]) + 1)

                if(blocks[i+1][0] == c):
                    res += blocks[i+1][1]

            res += 1

            ans = max(ans,res)

        if(i != 0):
            ans = max(ans, max(blocks[i][1],blocks[i-1][1]) + 1)
            
        if(i != len(blocks)-1):
            ans = max(ans, max(blocks[i][1], blocks[i+1][1]) + 1)
                    
            
    print(ans)


    
    



        
        