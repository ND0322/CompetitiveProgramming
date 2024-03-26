for _ in range(int(input())):
    freq = {}

    n,k = map(int,input().split(" "))

    for i in range(n):
        s = input()

        if(s in freq):
            freq[s] += 1
        else:
            freq[s] = 1

    

    num = []

    for i in range(n+1):
        num.append([])
    freq = list(freq.items())

    #print(freq)
    
    

    if(k % 100 > 3 and k % 100 < 21):
        print(str(k) + "th most common word(s):")
    else:
        if(k % 10 == 1):
            print(str(k) + "st most common word(s):")
        elif(k % 10 == 2):
            print(str(k) + "nd most common word(s):")
        elif(k % 10 == 3):
            print(str(k) + "rd most common word(s):")
        else:
            print(str(k) + "th most common word(s):")

    #print(freq)
    vals = {}
    for i in freq:
        num[i[1]].append(i[0])

        if(i[1] not in vals):
            vals[i[1]] = 1
        else:
            vals[i[1]] += 1
        

    #print(num)

    #vals = sorted(vals, reverse= True)

    vals = dict(sorted(vals.items(), reverse= True))

    pref = 0
    for i in vals:
        if(pref == k-1):
            for j in num[i]:
                print(j)
            break

        pref += vals[i]


    print()

   

        
    
   
    
    

    
