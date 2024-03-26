data = open('in.txt', 'r').read().split('\n')

ans = 0
for i in data:
    
    id = int(i[5:i.index(":")])

    i = i[i.index(":")+2:]
    sep = i.split("; ")

    cntr = 0
    cntg = 0
    cntb = 0
    

    flag = True
    for j in sep:
        kms = j.split(", ")
        

        for l in kms:
            if(l.split(" ")[1] == 'blue'):
                cntb = max(cntb, int(l.split(" ")[0]))
            if(l.split(" ")[1] == 'red'):
                cntr = max(cntr, int(l.split(" ")[0]))
            if(l.split(" ")[1] == 'green'):
                cntg = max(cntg, int(l.split(" ")[0]))
       
    ans += cntr * cntg * cntb


print(ans)