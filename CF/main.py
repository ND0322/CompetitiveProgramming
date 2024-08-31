s = input()

ans = 0
for i in range(len(s)):
    for j in range(i+1, len(s)):
        if(s[i] == s[j]):
            ans+=1
            print(i,j)
            continue
            
        for k in range(i, j):
            if((s[k] != s[i] or s[k] != s[j]) and s[k] != s[k+1]):
                break
print(ans)