s = set()

for i in range(100000):
    n = i*i

    if(n == 256):
        continue
    if(str(n)[len(str(n))-3:] == "256"):
        s.add(int(str(n)[:len(str(n))-3]))

l = list(s)

l.sort()

print(l)
print(l[9]%1000)