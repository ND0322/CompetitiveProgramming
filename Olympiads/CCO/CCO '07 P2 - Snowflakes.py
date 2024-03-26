import math

def hash(a):
    ans = 1

    for i in range(6):
        ans *= (a[i]+1) + (a[(i+1)%6]+1)
    
    return ans

n = int(input())


s = set()


for _ in range(n):

    s.add(hash(list(map(int,input().split(" ")))))

if(len(s) != n):
    print("Twin snowflakes found.")
else:
    print("No two snowflakes are alike.")
   

   


        


   


