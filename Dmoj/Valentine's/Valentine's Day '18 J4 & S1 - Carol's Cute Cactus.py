import math

l,r= map(int,input().split(" "))

ans = 0
best = -1

for i in range(10000):
    a = int(str(i) + str(i)[::-1])

    if(a >= l and a <= r):

        if(min(abs(r-a), abs(a-l)) > ans):
            ans = min(abs(r-a), abs(a-l))
            best = a
        elif(min(abs(r-a), abs(a-l)) == ans):
            best = max(best, a)
             
    
    
    b = int(str(i) + str(i)[:len(str(i))-1][::-1])

    if(b >= l and b <= r):
        

        if(min(abs(r-b), abs(b-l)) > ans):
            ans = min(abs(r-b), abs(b-l))
            best = b
        elif(min(abs(r-b), abs(b-l)) == ans):
            best = max(best, b)

        
        

print(best)
#print(ans)