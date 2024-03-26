import sys

sys.stdin = open("bcount.in", "r")
sys.stdout = open("bcount.out", "w")

n,q = map(int,input().split(" "))

cows = []

for i in range(n):
  cows.append(int(input()))

psum = [[0,0,0]]

for i in range(n):
  add = [0,0,0]
  add[cows[i]-1] += 1

  add[0] += psum[-1][0]
  add[1] += psum[-1][1]
  add[2] += psum[-1][2]

  psum.append(add)


for i in range(q):
  l,r = map(int,input().split(" "))

  print(psum[r][0]-psum[l-1][0],psum[r][1]-psum[l-1][1],psum[r][2]-psum[l-1][2])