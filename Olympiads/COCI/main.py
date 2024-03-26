def solve(a,b):
    if(a == b):
        return a
    if(a > b):
        return solve(a-b,b)
    else:
        return solve(b,a)

print(solve(10,8))