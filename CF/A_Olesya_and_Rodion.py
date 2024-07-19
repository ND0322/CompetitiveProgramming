def find_divisible_number(n, t):
    
    lower_bound = 10**(n-1)

    upper_bound = 10**n - 1
    
    
    if lower_bound % t == 0:
        result = lower_bound
    else:
        result = (lower_bound // t + 1) * t
    
    
    if result <= upper_bound:
        return result
    else:
        return -1

n,k = map(int,input().split(" "))
print(find_divisible_number(n, k)) 
