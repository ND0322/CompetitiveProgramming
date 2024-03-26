from collections import deque

n,k = map(int, input().split())
s = input()
t = input()

dq = deque()

ans = 0
for i in range(n):
    if len(dq) > 0 and dq[0][0] < i:
        ans += abs(dq[0][1])
        dq.append((dq[0][0] + k, dq[0][1]))
        dq.popleft()
    if s[i] != t[i]:
        val = pow(-1, s[i] != '1')
        if len(dq) == 0 or abs(dq[0][1] + val) > abs(dq[0][1]):
            if not (len(dq) > 0 and dq[0][0] == i):
                dq.appendleft((i, 0))
            dq[0] = dq[0][0], dq[0][1] + val
        else:
            dq[0] = dq[0][0], dq[0][1] + val
            if dq[0][1] == 0:
                dq.popleft()

print(ans)