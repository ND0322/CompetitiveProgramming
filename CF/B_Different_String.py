for _ in range(int(input())):
    s = input()

    if s == s[0] * len(s):
        print("NO")
        continue
    
    print("YES")

    print(s[1:] + s[0])