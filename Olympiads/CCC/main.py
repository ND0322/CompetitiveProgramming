q = int(input())


l = [(0,0)]

added = [(0,0)]

ans = 0
cnt = 0
for _ in range(q):
    c = input()

    if(c[0] == 'A'):
        s,t = map(int,c[2:].split(" "))
        

        #s = (s + ans) % (1e6+3)
        #t = (t + ans) % (1e6+3)


        added.append((s,t))
        l.append((s,t))
        cnt += 1
    else:
        pos = int(c[2:])

        #pos = int((pos + ans) % (1e6+3))

        l.remove(added[pos])

    
    b = sorted(l)

    cur = 0

    for i in b:
        if(i[0] > cur):
            cur = i[0] + i[1]
        else:
            cur += i[1]

    
    ans = cur-1
    print(int(ans))


        

