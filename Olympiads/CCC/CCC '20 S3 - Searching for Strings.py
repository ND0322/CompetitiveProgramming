def getPow():
    pow1 = 1
    pow2 = 1

    for i in range(len(n)-1):
        pow1 = (pow1 * p1) % MOD1
        pow2 = (pow2 * p2) % MOD2
    
    return (pow1,pow2)


def solve():

   

    if(len(n) > len(h)):
        print(0)
        return
    

    s1 = set()
    s2 = set()


    freqN = [0] * 26
    freqH = [0] * 26

    
    
    for i in range(0, len(n)):
        freqN[ord(n[i])-ord("a")]+=1


    pow1, pow2 = getPow()

   


    phashN = 0
    phashH = 0
    ans = 0



    for i in range(1, len(h)+1):
        freqH[ord(h[i-1]) - ord("a")] += 1

        phashN = (phashN * p1 + ord(h[i-1])) % MOD1
        phashH = (phashH * p2 + ord(h[i-1])) % MOD2

        


       

        if(i >= len(n)):

            

            can = 1

            for j in range(26):
                can &= (freqN[j] == freqH[j])
            #print(can)
            if(can and not (phashN in s1 and phashH in s2)):
                ans += 1
                s1.add(phashN)
                s2.add(phashH)

            
           

            freqH[ord(h[i - len(n)]) - ord("a")] -= 1
            phashN = (phashN - (pow1 * ord(h[i - len(n)])%MOD1) + MOD1) % MOD1
            phashH = (phashH - (pow2 * ord(h[i - len(n)])%MOD2) + MOD2) % MOD2

    
       

    print(ans)
        


        
p1 = 177
p2 = 217
MOD1 = 1e9+7
MOD2 = 1e9+7

n = input()
h = input()

   
solve()