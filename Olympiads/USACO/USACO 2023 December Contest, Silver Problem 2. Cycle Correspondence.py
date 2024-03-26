n,k = map(int,input().split(" "))



a = list(map(int,input().split(" ")))
b = list(map(int,input().split(" ")))


ansa = len(set(range(1,n+1)) - set(a)- set(b))

idb = {}


for i in range(k):
   
    idb[b[i]] = i

c = [0] * k
for i in range(k):
    if(a[i] in idb):
        c[i-idb[a[i]]] += 1

ans = max(c)

c = [0] * k


a = a[::-1]

for i in range(k):
    if(a[i] in idb):
        c[i-idb[a[i]]] += 1

ans = max(ans, max(c))







print(ans + ansa)