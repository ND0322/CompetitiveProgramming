n = int(input())

wins = []




for i in range(n):
    s = input()

    cnt = 0
    for j in range(n):


        if(s[j] == "o"):
            cnt += 1

    wins.append((-cnt, i+1))
        
wins.sort()

for i in wins:
    print(i[1])
