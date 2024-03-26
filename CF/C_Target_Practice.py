for _ in range(int(input())):

    hit = []

    for i in range(10):
        s = input()

        for j in range(10):
            if s[j] == "X":
                hit.append((i,j))



    ans = 0

    for x,y in hit:
        if y == 0 or x == 0 or y == 9 or x == 9:
            ans += 1

        if (y == 1 or y == 8) and x > 0 and x < 9:
            ans += 2
        
        elif (x == 1 or x == 8) and y > 0 and y < 9:
            ans += 2

        if (y == 2 or y == 7) and x > 1 and x < 8:
            ans += 3
        
        elif (x == 2 or x == 7) and y > 1 and y < 8:
            ans += 3

        if (y == 3 or y == 6) and x > 2 and x < 7:
            ans += 4
        
        elif (x == 3 or x == 6) and y > 2 and y < 7:
            ans += 4

        if (y == 4 or y == 5) and x > 3 and x < 6:
            ans += 5
        
        elif (x == 4 or x == 5) and y > 3 and y < 6:
            ans += 5

        
    
    print(ans)