t = input()
ans = 0

wait = [0] * 7
temp = len(t)


for i in t:

  wait[0] += 1
  for j in range(5,-1,-1):
    if i == "bessie"[j]:
      wait[j+1] += wait[j]
      wait[j] = 0

  ans += wait[6] * temp
  wait[0] += wait[6]
  wait[6] = 0
  temp-= 1



print(ans)
  