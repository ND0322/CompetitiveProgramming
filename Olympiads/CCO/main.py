ans = 0

for i in range(1,8):
    for j in range(i+1, 8):
        if(j >= 2 * i):
            ans+=1

print(ans)