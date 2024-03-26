for _ in range(int(input())):
    n = int(input())

    s = input()


    l = []

    for i in range(27):
        l.append(0)

    for i in s:
        l[ord(i)-ord("A")+1] += 1
    
    ans = 0

    for i in range(1,27):
        if(l[i] >= i):
            ans+=1
    
    print(ans)