MOD = 1e9+7

def pow(n):
    ans = 1

    for i in range(n):
        ans = (ans * 3) % MOD
    return ans
def solve():

    n = int(input())


    mn = 0

    cnt = 0

    a = list(map(int,input().split(" ")))

    for i in a:
        if(i == 1):
            cnt += 1
        else:
            mn += i

    mn %= MOD
    if(cnt == n):
        print(1)
        if(n < 5):
            print(n)
        else:
            three = n//3

            if(n%3 == 0):
                print(int(pow(three)%MOD))
            if(n%3 == 1):
                print(int((pow(three-1) * 4)%MOD))
            if(n%3 == 2):
                print(int((pow(three) * 2)%MOD))
        return
    
    for i in range(n):
        if(cnt and a[i] == 2):
            a[i]+=1
            cnt-=1

    mn = int(mn)

    if(cnt == 0):
        print(mn)
        mx = 1

        for i in range(n):
            mx = (mx*a[i]) % MOD
        
        print(int(mx))
    
    if(cnt == 1):
        mx = 1
        small = -1

        for i in range(n):
            if(a[i] != 1 and (a[small] > a[i] or small == -1)):
                small = i

        a[small] += 1
    
        for i in range(n):
            mx = (mx*a[i]) % MOD
        print(mn)
        print(int(mx))
    
    if(cnt > 1):
        mx = 1

        for i in range(n):
            mx = (mx*a[i])


        ans = 1

        for i in range(n):
            ans = (ans * 2) % MOD

        

        
        three = cnt//3



        if(cnt%3 == 0):
            best = int(pow(three)%MOD)
        if(cnt%3 == 1):
            best = int((pow(three-1) * 4))
        if(cnt%3 == 2):
            best = int((pow(three) * 2)%MOD) 
        print(mn)
        print(int((best * mx)%MOD))




print((pow(50000 + 8332) * 4) % MOD)



solve()