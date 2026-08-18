n = int(input())

for a in range(n+1):
    for b in range(a+1, n+1):
        if(2*b-a > n):
            break
        if(a ^ b ^ (2*b-a) == 0):
            print(bin(a)[2:],bin(b)[2:],bin(2*b-a)[2:])