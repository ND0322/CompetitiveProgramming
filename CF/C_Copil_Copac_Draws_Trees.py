def find(x):
    
    if x == parents[x]:
        return x
    parents[x] = find(parents[x])
    return parents[x]

def union(x,y):
    x = find(x)
    y = find(y)

   
    if x != y:
        if size[x] < size[y]:
            temp = x
            x = y
            y = x
        parents[y] = x
        size[x] += size[y]
    

for _ in range(int(input())):
    n = int(input())

    parents = [0]
    size = [1] * (n+1)

    for i in range(1,n+1):
        parents.append(i)
    
    edges = []

    for i in range(n-1):
        edges.append(tuple(map(int,input().split(" "))))
    

    tot = 0
    ans = 0

    while tot == n-1:
        
        for edge in edges:
            if(find(edge[0]) == 1 and find(edge[1]) != 1):
                tot += 1
                union(edge[1],edge[0])
            elif(find(edge[1]) == 1 and find(edge[0]) != 1):
                tot += 1
                union(edge[0],edge[1])
        print(parents)
        print(tot)
        ans +=1

    print(ans)