for _ in range(int(input())):
    n = int(input())
    s = input()
    e = set()

    for i in range(n-1):
        e.add(s[i] + s[i+1])
    
    print(len(e))