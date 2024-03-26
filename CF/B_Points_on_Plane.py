for _ in range(int(input())):
    n = int(input())

    
    ans = n**(1/2)
    while (ans * ans > n):
            
        ans-= 1
    while (ans * ans < n):
            
        ans += 1
    print(ans - 1)