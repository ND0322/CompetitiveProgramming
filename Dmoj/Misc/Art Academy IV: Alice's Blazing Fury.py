n, m, q, tot = map(int, input().split())

h = [False] * (MAXN << 2)
lz = [0] * (MAXN << 2)
st = [0] * (MAXN << 2)
rr = [0] * (MAXN << 1)

class Node:
    def __init__(self):
        self.lz = -1
        self.val = 0

lr = [[] for _ in range(MAXN)]

def push(i):
    if h[i >> 1]:
        st[i] = lz[i >> 1]
        lz[i] = lz[i >> 1]
        h[i] = True
        st[i ^ 1] = lz[i >> 1]
        lz[i ^ 1] = lz[i >> 1]
        h[i ^ 1] = True
        h[i >> 1] = False

def pushdown(i):
    k = 0
    while i >> k > 0:
        k += 1
    k -= 2
    while k >= 0:
        push(i >> k)
        k -= 1

def pop(i):
    if h[i >> 1]:
        st[i >> 1] = lz[i >> 1]
    else:
        st[i >> 1] = max(st[i], st[i ^ 1])

def popup(i):
    while i > 1:
        pop(i)
        i >>= 1

def update(l, r, v):
    l += tot
    r += tot
    tmp = (l, r)
    pushdown(l)
    pushdown(r)
    while l < r:
        if l & 1:
            st[l] = v
            lz[l] = v
            h[l] = True
            l += 1
        if r & 1:
            r -= 1
            st[r] = v
            lz[r] = v
            h[r] = True
        l >>= 1
        r >>= 1
    popup(tmp[0])
    popup(tmp[1])

def query(l, r):
    l += tot
    r += tot
    pushdown(l)
    pushdown(r)
    ans = 0
    while l < r:
        if l & 1:
            ans = max(ans, st[l])
            l += 1
        if r & 1:
            r -= 1
            ans = max(ans, st[r])
    return ans

def pdwn(node, c):
    if lr[c][node].lz != -1:
        lr[c][node << 1].lz = lr[c][node].lz
        lr[c][node << 1 | 1].lz = lr[c][node].lz
        lr[c][node << 1].val = lr[c][node].lz
        lr[c][node << 1 | 1].val = lr[c][node].lz
        lr[c][node].lz = -1

def modify(node, l, r, x, y, v, c):
    if x > r or y < l:
        return
    if x <= l and y >= r:
        lr[c][node].val = v
        lr[c][node].lz = v
        return
    mid = (l + r) >> 1
    pdwn(node, c)
    modify(node << 1, l, mid, x, y, v, c)
    modify(node << 1 | 1, mid + 1, r, x, y, v, c)
    lr[c][node].val = max(lr[c][node << 1].val, lr[c][node << 1 | 1].val)

def ql(node, l, r, x, y, c):
    if x > r or y < l:
        return 0
    if x <= l and y >= r:
        return lr[c][node].val
    mid = (l + r) >> 1
    pdwn(node, c)
    return max(ql(node << 1, l, mid, x, y, c), ql(node << 1 | 1, mid + 1, r, x, y, c)

for i in range(1, n + 1):
    lr[i] = [Node() for _ in range((m + 1) << 2)]
for i in range(n + 1, n + m + 1):
    lr[i] = [Node() for _ in range((n + 1) << 2)]

for _ in range(q):
    opt, x, y, z = map(int, input().split())
    if opt == 1:
        for i in range(x, x + z):
            l = y
            r = y + z - 1
            df = m * (i - 1)
            ll = ql(1, 1, m, l - 1, l - 1, i)
            if ll:
                l = ll
            rl = ql(1, 1, m, r + 1, r + 1, i)
            if rl:
                r = rr[df + rl]
                rr[df + rl] = 0
            modify(1, 1, m, l, r, l, i)
            rr[df + l] = r
            update(df + l, df + r + 1, r - l + 1)
        for i in range(y, y + z):
            l = x
            r = x + z - 1
            df = n * m + n * (i - 1)
            ll = ql(1, 1, n, l - 1, l - 1, i + n)
            if ll:
                l = ll
            rl = ql(1, 1, n, r + 1, r + 1, i + n)
            if rl:
                r = rr[df + rl]
                rr[df + rl] = 0
            modify(1, 1, n, l, r, l, i + n)
            rr[df + l] = r
            update(df + l, df + r + 1, r - l + 1)
    if opt == 2:
        for i in range(x, x + z):
            l = y
            r = y + z - 1
            df = m * (i - 1)
            update(df + l, df + r + 1, 0)
            sl = ql(1, 1, m, l, l, i)
            sr = rr[df + sl]
            if sl != l:
                rr[df + sl] = l - 1
            if r != sr:
                rr[df + r + 1] = sr
                modify(1, 1, m, r + 1, sr, r + 1, i)
            modify(1, 1, m, l, r, 0, i)
            update(df + sl, df + l, l - sl)
            update(df + r + 1, df + sr + 1, sr - r)
        for i in range(y, y + z):
            l = x
            r = x + z - 1
            df = n * m + n * (i - 1)
            update(df + l, df + r + 1, 0)
            sl = ql(1, 1, n, l, l, i + n)
            sr = rr[df + sl]
            if sl != l:
                rr[df + sl] = l - 1
            if r != sr:
                rr[df + r + 1] = sr
                modify(1, 1, n, r + 1, sr, r + 1, i + n)
            modify(1, 1, n, l, r, 0, i + n)
            update(df + sl, df + l, l - sl)
            update(df + r + 1, df + sr + 1, sr - r)
    if opt == 3:
        ans = 0
        for i in range(x, x + z):
            ans = max(ans, query((i - 1) * m + y, (i - 1) * m + y + z))
            if ans == m:
                break
        for i in range(y, y + z):
            ans = max(ans, query(n * m + n * (i - 1) + x, n * m + n * (i - 1) + x + z))
            if ans == n:
                break
        print(ans)