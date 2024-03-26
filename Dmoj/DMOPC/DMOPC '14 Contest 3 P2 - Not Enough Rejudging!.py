from math import floor
n = int(input())

cnt = 0

l = []


for _ in range(n):
    i = input()
    l.append(i)
    if(i == 'WA'):
        cnt+=1

cnt*= .3
cnt = floor(cnt)



cntI = 0

for i in l:
    if(i == 'AC'):
        print("AC")

    if(i == "WA"):
        if(cnt > 0):
            print("AC")
        else:
            print("WA")
        cnt-=1
    if(i == 'TLE'):
        print("WA")
    
    if(i == "IR"):
        if(cntI < 10):
            print("AC")
        elif(cntI < 20):
            print("WA")
        else:
            print("IR")
        cntI+=1
    
    #print(cnt)
