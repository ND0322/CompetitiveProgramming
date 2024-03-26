import sys
from queue import Queue

sys.stdin = open("feast.in","r")
sys.stdout = open("feast.out","w")


t,a,b = map(int,input().split(" "))



visited = [[False] * 2 for i in range(t+1)]

visited[0][0] = True
q = Queue()

q.put((0,0))

while not q.empty():
  cap,w = q.get()

  if cap + a <= t:
    if not visited[cap+a][w]:
      visited[cap+a][w] = True
      q.put((cap+a,w))
  if cap + b <= t:
    if not visited[cap+b][w]:
      visited[cap+b][w] = True
      q.put((cap+b,w))
      
  if not w:
    if not visited[cap//2][1]:
      visited[cap//2][1] = True
      q.put((cap//2,1))


for i in range(t,-1,-1):
  if visited[i][0] or visited[i][1]:
    print(i)
    break
  
  
  



#print(solve(0,0))