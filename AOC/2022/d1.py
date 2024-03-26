data = open('in.txt', 'r').read().split('\n')

l = []

cur = 0

for i in data:
    if i == '':
        l.append(cur)
        cur = 0
    else:
        cur += int(i)

l.sort(reverse= True)

print(l[0] + l[1] + l[2])