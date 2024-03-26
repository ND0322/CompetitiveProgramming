for _ in range(int(input())):
    a,b,r = map(int,input().split(" "))
    c = a ^ b
    ans = float('inf')
    mask = 1 << (c.bit_length() - 1)
    
    while mask > 0:
        x = r | (c & ~(mask - 1))
        ans = min(ans, abs((a ^ x) - (b ^ x)))
        mask >>= 1
    
    print(ans)


