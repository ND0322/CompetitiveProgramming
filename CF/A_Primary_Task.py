for _ in range(int(input())):
    s = input()

    if(s[:2] == '10' and int(s[2:]) >= 2 and s[2] != '0'):
        print("YES")
    else:
        print("NO")