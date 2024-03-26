def findDiscardSum(originalRows, tiles):
    row = list(str(originalRows))
    
    tiles = tiles.split(" ")

    ans = 0

    check = False
    r = 0

    for i in tiles:
        if check:
            if i[0] == row[r]:
                check = (i[0] == i[1])
                row[r] = i[1]
            elif i[1] == row[r]:
                check = (i[0] == i[1])
                row[r] = i[0]

            else:
                #print("a", i)
                ans += int(i[0]) + int(i[1])
            continue
        
        else:
            flag = True
            for j in range(4):
                tmp = (r+j)%4

                if row[tmp] == i[0]:
                    row[tmp] = i[1]
                    flag = False
                    if(i[0] == i[1]):
                        check = True
                        r = tmp
                    else:
                        r = (r+j+1)%4
                    break

                if row[tmp] == i[1]:
                    row[tmp] = i[0]
                    flag = False
                    if(i[0] == i[1]):
                        check = True
                        r = tmp
                    else:
                        r = (r+j+1)%4
                    break

            if flag:
                #print("b", i)
                ans += int(i[0]) + int(i[1])
    return ans


x = int(input())
y = input()

print(findDiscardSum(x,y))