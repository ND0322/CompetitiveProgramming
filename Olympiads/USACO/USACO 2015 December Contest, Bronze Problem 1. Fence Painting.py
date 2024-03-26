import sys
sys.stdin = open("paint.in","r")
sys.stdout = open("paint.out","w")


a,b = map(int,input().split(" "))
c,d = map(int,input().split(" "))


if a<=d and c<=b:
  print(abs(max(a,b,c,d) - min(a,b,c,d)))
else:
  
  print(b-a + d-c)