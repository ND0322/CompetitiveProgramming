


for _ in range(int(input())):

    n = int(input())

    if(n < 7):
        print("NO")
        continue

    lo = 2  
    hi = int(n**0.5) + 1  

    flag = True

    while lo <= hi:
        mid = (lo + hi) // 2
        curs = 0
        curp = 1

        while curs < n:
            curs += curp
            curp *= mid
            

        if curs == n:
            print("YES")
            flag = False
            break
        elif curs < n:
            lo = mid + 1
        else:
            hi = mid - 1

    if flag:
        print("NO")


