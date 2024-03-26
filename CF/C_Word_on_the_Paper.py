def solve():
    grid = []

    for i in range(8):
        grid.append(list(input()))
    
    grid = list(zip(*grid[::-1]))

 

    ans = ""

    for i in range(8):
        for j in range(8):
            if grid[i][j] != ".":

                

                ans += grid[i][j]

                


                for k in range(j+1,8):
                    
                    if(grid[i][k] == "."):
                        print(ans[::-1])
                        return

                    ans += grid[i][k]

                print(ans[::-1])
                return

for _ in range(int(input())):
    solve()
    
                

    