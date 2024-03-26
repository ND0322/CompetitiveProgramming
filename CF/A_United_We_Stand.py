for _ in range(int(input())):
    n = int(input())

    a = sorted(list(map(int,input().split(" "))))

    if(a[0] == a[-1]):
        print(-1)
        continue

    cnt = 0

    for i in range(n):
        if a[i] != a[0]:
            break
        else:
            cnt+=1

    a = list(map(str,a))

    
    print(cnt, n-cnt)
    
    print(" ".join([a[0]] * cnt))

    print(" ".join(a[cnt:]))