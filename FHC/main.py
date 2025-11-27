l,r,kk = map(int,input().split(" "))


cnt = 0
for i in range(l, r+1):
    

    for j in range(len(str(i))):
        sm = 0

        flag = 0

        for k in range(j, len(str(i))):
            sm += int(str(i)[k])

            if(sm % kk == 0):
                cnt+=1
                print(i)
                flag = 1
                break
        
        if(flag):
            break
print(cnt)