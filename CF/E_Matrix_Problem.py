from collections import namedtuple
from queue import Queue




edge = namedtuple("edge", "v c w id")

INF = 1e18
BIG = 1e9

n,m = map(int,input().split(" "))

ans = 0
tot = 0

N = n+m+10

dist = [INF] * N
cnt = [0] * N
inq = [False] * N
adj = [[] for i in range(N)]

grid = []

for i in range(n):
    grid.append(list(map(int,input().split(" "))))

    

rs = 0
cs = 0

x = list(map(int,input().split(" ")))


for i in range(n):
    

    rs += x[i]

    adj[0].append(edge(i+2, x[i], 0, len(adj[i+2])))
    adj[i+2].append(edge(0, 0,0, len(adj[0])-1))

x = list(map(int,input().split(" ")))

for i in range(m):

    cs += x[i]

    adj[i+n+2].append(edge(1,x[i], 0, len(adj[1])))
    adj[1].append(edge(i+n+2, 0, 0, len(adj[i+n+2])-1))

tmp = 0

for i in range(n):
    for j in range(m):
        tmp += grid[i][j]
    
        adj[i+2].append(edge(j+n+2, 1, BIG + 2*(grid[i][j] == 0)-1, len(adj[j+n+2])))
        adj[j+n+2].append(edge(i+2, 0, -(BIG + 2*(grid[i][j] == 0)-1), len(adj[i+2])-1))




def spfa():
    q = Queue()

    for i in range(N):
        dist[i] = INF
        cnt[i] = 0
        inq[i] = False


    dist[0] = 0

    q.put(0)

    while(not q.empty()):
        node = q.get()
        inq[node] = False

        for child,c,w,id in adj[node]:
            if(c > 0 and dist[child] > dist[node] + w):
                dist[child] = dist[node] + w
                if(not inq[child]):
                    inq[child] = True
                    q.put(child)
                    
    for i in range(N):
        inq[i] = False
    return dist[1] != INF

def dfs(node = 0, f = INF):
    
    if(node == 1):
        global tot
        tot += f * dist[node]
        return f
    
    
    
    ret = 0

    inq[node] = True

    while(cnt[node] < len(adj[node])):
        e = adj[node][cnt[node]]
        child = e.v
        
        if(not inq[child] and e.c > 0 and dist[child] == dist[node] + e.w):
            tmp = dfs(child, min(e.c, f))

            
            ret += tmp

            adj[node][cnt[node]] = edge(e.v, e.c - tmp, e.w, e.id)
            adj[child][e.id] = edge(node, adj[child][e.id].c+tmp, adj[child][e.id].w, adj[child][e.id].id)
            
            f -= tmp
            if(not f):
                break
        
        cnt[node] += 1

    inq[node] = 0
    if(not ret):
        dist[node] = INF
    
    return ret 
    
while(spfa()):
    ans += dfs()
    print("")

#print(ans,tot)



if(cs != rs):
    print("-1")
elif ans != rs:
    print("-1")
else:
    print(int(tot - BIG * rs + tmp))
    


       


