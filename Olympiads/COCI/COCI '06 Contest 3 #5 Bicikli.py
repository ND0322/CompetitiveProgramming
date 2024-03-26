from queue import Queue

def dfs(node):
  if not visited[node]:
    visited[node] = True
    r[node] = True

    for child in adj[node]:
      if not visited[child] and dfs(child):
        return True;
      elif r[child]:
        return True

  r[node] = False
  return False

def solve(node):
  if node == 2:
    return 1

  if dp[node] == -1:
    dp[node] = 0

    for child in adj[node]:
      dp[node] += solve(child)

  return dp[node]
    

n,m = map(int,input().split(" "))

adj = [[] for i in range(n+1)]
rev = [[] for i in range(n+1)]

for i in range(m):
  x,y = map(int,input().split(" "))
  adj[x].append(y)
  rev[y].append(x)


q = Queue()
visited = [False] * (n+1)
visited[1] = True
q.put(1)

while not q.empty():
  node = q.get()

  for child in adj[node]:
    if not visited[child]:
      visited[child] = True
      q.put(child)


for i in range(1,n+1):
  if not visited[i]:
    adj[i] = []

visited = [False] * (n+1)
visited[2] = True
q.put(2)

while not q.empty():
  node = q.get()

  for child in rev[node]:
    if not visited[child]:
      visited[child] = True

      q.put(child)


for i in range(1,n+1):
  if not visited[i]:
    adj[i] = []




visited = [False] * (n+1)
r = [False] * (n+1)

check = True

for i in range(1,n+1):
  if not visited[i] and dfs(i):
    print("inf")
    check = False
    break

dp = [-1] * (n+1)
if(check):
  ans = str(solve(1))
  if len(ans) <= 9:
    print(ans)
  else:
    p =""
    for i in range(len(ans)-1,len(ans)-10,-1):
      p += ans[i]

    print(p[::-1])