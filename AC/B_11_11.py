n = int(input())
D = [*map(int, input().split())]
ans = 0
for i, d in enumerate(D):
    month_str = str(i + 1)
    for x in range(d):
        day_str = str(x + 1)
        if len(set(month_str + day_str)) == 1:
            ans += 1
            
print(ans)