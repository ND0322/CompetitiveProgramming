import sys

sys.stdin = open("highcard.in","r")
sys.stdout = open("highcard.out","w")

n = int(input())

opp = [False] * (2*n+1)


e = []
b = []
for i in range(n):
  opp[int(input())] = True
for i in range(1,2*n+1):
  if opp[i]:
    e.append(i)
  else:
    b.append(i)

e.sort()
b.sort()

ans = 0

indB = 0
indE = 0


while(indB < n and indE < n):
  if(e[indE] < b[indB]):
    ans += 1
    indE += 1
    indB+=1
  else:
    indB+=1

print(ans)
  