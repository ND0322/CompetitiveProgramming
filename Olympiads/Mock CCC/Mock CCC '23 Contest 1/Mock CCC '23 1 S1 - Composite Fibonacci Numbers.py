fib = [False] * 100005

fib[0] = True
fib[1] = True

i = 1
j = 0

while(i+j <= 100000):
    tmp = i
    i = i+j
    j = tmp

    fib[i] = True

def solve(s):
    if(fib[int(s)] and int(s) != n):
        return True
    
    for i in range(1,len(s)):
        if(solve(s[:i]) and solve(s[i:])):
            return True

    return False


for _ in range(int(input())):
    n = int(input())

    if(solve(str(n))):
        print("YES")
    else:
        print("NO")