n = int(input())

A = []

for i in range(n):
	A.append([0] * (n+1))

for i in range(1,n):
	l = list(map(int,input().split(" ")))
	
	for j in range(i+1, n+1):
		A[i][j] = l[j-i-1]




    
x, y, sx, sy = 1, 1, 0, 0 # Initialize x and y to 1, sx and sy to 0
for i in range(2, n + 1): # loop from 2 to N
    if sx + A[x][i] < sy + A[y][i]:
        sx += A[x][i]
        x = i
    else:
        sy += A[y][i]
        y = i
print(x,y)
print(sx+sy)

