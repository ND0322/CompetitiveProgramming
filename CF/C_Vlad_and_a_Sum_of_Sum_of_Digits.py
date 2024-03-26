ans = [0]

for i in range(1,200001):
        ans.append(ans[i-1])
        for j in str(i):
            ans[i] += int(j)





for _ in range(int(input())):
    n = int(input())
    
    print(ans[n])