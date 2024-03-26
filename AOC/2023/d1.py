data = open('in.txt', 'r').read().split('\n')

bank = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
d = {"one" : 1, "two" : 2, "three" : 3, "four" : 4, "five" : 5, "six" : 6, "seven" : 7, "eight" : 8, "nine" : 9}

ans = 0

for i in data:
    tmp = len(i)+1
    cur = 0
    for j in range(len(i)):
        
        if i[j].isnumeric():
            tmp = j
            cur = int(i[j])
            break

   
    for j in bank:
        if j in i:
            if(i.index(j) < tmp):
                cur = d[j]
                tmp = i.index(j)
    
    ans += 10*cur

    i = i[::-1]

    tmp = len(i)+1
    cur = 0
    for j in range(len(i)):
        
        if i[j].isnumeric():
            tmp = j
            cur = int(i[j])
            break

   
    for j in bank:
        t = j[::-1]
        if t in i:   
            if(i.index(t) < tmp):
                cur = d[j]
                tmp = i.index(t)    
    
    ans += cur

print(ans)