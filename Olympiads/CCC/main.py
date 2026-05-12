n = int(input())

sm = 0
cap = []

for i in range(n):
    #liquid, volume = map(int,input().split(" "))
    inp = input().split(" ")

    liquid = int(inp[0])
    volume = int(inp[1])

    sm += liquid

    cap.append((volume, i))

cap.sort(reverse=True)

ans = [0 for i in range(n)]
#[0,0,0,0,0...0]

for i in range(n):

    if(sm >= cap[i][0]):
        ans[cap[i][1]] = cap[i][0]
        sm -= cap[i][0]
    else:
        ans[cap[i][1]] = sm
        break

print(ans.count(0))
print(" ".join(list(map(str, ans))))
        













