for _ in range(int(input())):

    s = input()

    if(s[0] == "0"):
        print(-1)
        continue

    ind = -1
    for i in range(1,len(s)):
        if(s[i] != "0"):
            ind = i
            break

    if(ind == -1):
        print(ind)
        continue



    a = int(s[:ind])
    b = int(s[ind:])
    

    if(a >= b):
        print(-1)
    else:
        print(a,b)
