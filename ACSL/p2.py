#could use smart splitting but this sh has super low constraints

s = input()


t = input().split(" ")

ans = ""

for i in range(len(t)):
    t[i] = list(map(int, t[i].split(".")))

    cnt = 1
    flag = False
    for j in range(len(s)):
        if(s[j] == '.' or s[j] == '!' or s[j] == '?'):
            cnt+=1
        
        if(cnt == t[i][0]):
            cnt = (not j)
            if(j == 0 and t[i][1] == 1):
                cnt = 0
                for l in range(0, len(s)):
                    cnt+=1
                    if(not s[l].isalnum()):
                        break
                    if(cnt == t[i][2]):
                        ans += s[l]
                        flag = 1
                        break
                break

            for k in range(j+1, len(s)):
                if(s[k].isalnum() and not s[k-1].isalnum()):
                    cnt += 1

                if(s[k] == '.' or s[k] == '!' or s[k] == '?'):
                    break
                if(cnt == t[i][1]):
                    cnt = 0
                    for l in range(k, len(s)):
                        cnt+=1
                        if(not s[l].isalnum()):
                            break
                        if(cnt == t[i][2]):
                            ans += s[l]
                            flag = True
                            break

                    break

            break
    
    if(not flag):
        ans += " "

print(ans)
