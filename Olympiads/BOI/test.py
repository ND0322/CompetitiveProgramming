def recur(a, c1,c2,c3,c4, c5, c6):
    if(len(a) == 16):
        for i in range(1,5):
            sm = 0

            for j in range(13):
                if(a[j] == i):
                    sm += j+1

            if(sm / 3 != 7):
                return
        
        print(a)
        exit()

    if(len(a) == 10):
        b = a.copy()
        b.append(5)
        recur(b, c1,c2,c3,c4, c5, c6)
        return
    
    if(c1 > 0):
        b = a.copy()
        b.append(1)
        recur(b, c1-1, c2, c3, c4, c5, c6)
        

    if(c2 > 0):
        b = a.copy()
        b.append(2)
        recur(b, c1, c2-1, c3, c4, c5, c6)


    if(c3 > 0):
        b = a.copy()
        b.append(3)
        recur(b, c1, c2, c3-1, c4, c5, c6)
      

    if(c4 > 0):
        b = a.copy()
        b.append(4)
        recur(b, c1, c2, c3, c4-1, c5, c6)

    if(c5 > 0):
        b = a.copy()
        b.append(5)
        recur(b, c1, c2, c3, c4, c5-1, c6)
    
    if(c6 > 0):
        b = a.copy()
        b.append(6)
        recur(b, c1, c2, c3, c4, c5, c6-1)


recur([], 3,3,3,3,3,3)

