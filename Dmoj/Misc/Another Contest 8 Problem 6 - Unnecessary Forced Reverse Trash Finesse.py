from collections import namedtuple
from queue import Queue

INF = 1e18


class MCF:

    edge = namedtuple("edge", "v c w id")



    def addEdge(self, u,v,c,w):
        self.adj[u].append(self.edge(v,c,w, len(self.adj[v])))
        self.adj[v].append(self.edge(u, 0, -w, len(self.adj[u])-1))


    def spfa(self):
        q = Queue()

        for i in range(self.N):
            self.dist[i] = INF
            self.cnt[i] = 0
            self.inq[i] = False


        self.dist[0] = 0

        q.put(0)

        while(not q.empty()):
            node = q.get()
            self.inq[node] = False

            for child,c,w,id in self.adj[node]:
                if(c > 0 and self.dist[child] > self.dist[node] + w):
                    self.dist[child] = self.dist[node] + w
                    if(not self.inq[child]):
                        self.inq[child] = True
                        q.put(child)
                        
        for i in range(self.N):
            self.inq[i] = False
        return self.dist[1] != INF

    def dfs(self, node = 0, f = 1e18):
        
        if(node == 1):
            self.tot += f * self.dist[node]
            return f
        
        
        
        ret = 0

        self.inq[node] = True

        while(self.cnt[node] < len(self.adj[node])):
            e = self.adj[node][self.cnt[node]]
            child = e.v
            
            if(not self.inq[child] and e.c > 0 and self.dist[child] == self.dist[node] + e.w):
                tmp = self.dfs(child, min(e.c, f))

                
                ret += tmp

                self.adj[node][self.cnt[node]] = self.edge(e.v, e.c - tmp, e.w, e.id)
                self.adj[child][e.id] = self.edge(node, self.adj[child][e.id].c+tmp, self.adj[child][e.id].w, self.adj[child][e.id].id)
                
                f -= tmp
                if(not f):
                    break
            
            self.cnt[node] += 1

        self.inq[node] = 0
        if(not ret):
            self.dist[node] = INF
        
        return ret 
        
    def dinic(self):
        while(self.spfa()):
            self.ans += self.dfs()
    
    def get_ans(self):
        return self.ans

    def get_tot(self):
        return self.tot

n = int(input())

left = [] 
right = []

for i in range(1,n+1):
    x,y = map(int,input().split(" "))

    if()


