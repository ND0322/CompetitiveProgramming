bank = ["0", "1", "8"]
def check(x):
    if(len(x) == 1):
        return x in bank
    
    if(len(x) & 1 and x[len(x)//2] not in bank):
        return False
    for i in range(len(x)//2):

        if(x[i] == "6"):

            if(x[len(x) - i - 1] != "9"):
          
                return False
            else:
                continue
        
        if(x[i] == "9"):

            if(x[len(x) - i - 1] != "6"):
          
                return False
            else:
                continue
    
        if x[i] not in bank:
            return False
        
        if(x[i] != x[len(x) - i - 1]):
            return False
    return True


l = int(input())
r = int(input())

ans = 0
for i in range(l, r+1):
    if(check(str(i))):
        ans+=1

print(ans)
