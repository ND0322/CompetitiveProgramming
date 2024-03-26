r = int(input())
c = int(input())

di = [-1,0,1,0]
dj = [0,1,0,-1]

grid = []

for i in range(r):
    grid.append(list(input()))

n = int(input())

t = []

for i in range(n):
    t.append(input())

last = []
offset = []

for i in range(4):
    offset.append(set())
    



for i in range(4):
    x = 0
    y = 0
    dir = i

    offset[i].add((x,y))

    for j in t:
        
        if(j == "F"):
            x += di[dir]
            y += dj[dir]
        
        if(j == "L"):
            dir = (dir+4-1) % 4
        if(j == "R"):
            dir = (dir+4+1)%4
        
        offset[i].add((x,y))
        
    
    last.append((x,y))

#print(last[0][0], last[0][1])





for i in range(r):
    for j in range(c):
        if grid[i][j] == "X": 
            continue

        for k in range(4):
            flag = True
            for a,b in offset[k]:
                
                if i + a < 0 or i + a >= r or j + b < 0 or j + b >= c:
                    flag = False
                    break
                if grid[i+a][j+b] == "X":
                    
                    flag = False
                    break

                
            
            if(flag):
                
                grid[i+last[k][0]][j+last[k][1]] = "*"

for i in range(r):
    print("".join(grid[i]))