s = input()

n = len(s)

psa = [[0 for j in range(26)] for i in range(n+1)]


for i in range(1, n+1):
    if(s[i-1] != " "):
        psa[i][ord(s[i-1]) - ord('a')]+=1

    for j in range(26):
        psa[i][j] += psa[i-1][j]

q = int(input())

for _ in range(q):
    l,r,c = map(str, input().split(" "))

    print(psa[int(r)][ord(c) - ord('a')] - psa[int(l)-1][ord(c) - ord('a')])



