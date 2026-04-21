import sys
input = sys.stdin.readline

MOD = 10**9 + 7

# fast exponentiation
def fastpow(a, b):
    res = 1
    a %= MOD
    while b > 0:
        if b & 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b >>= 1
    return res


# globals (filled later)
ranges = []
cnt = []
val = []
psa = []
n = m = q = 0


def ones(l, r):
    global ranges, cnt, m

    lo, hi = 1, m
    ll = 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if ranges[mid][0][0] >= l:
            hi = mid - 1
            ll = mid
        else:
            lo = mid + 1

    lo, hi = 1, m
    rr = 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if ranges[mid][0][1] <= r:
            lo = mid + 1
            rr = mid
        else:
            hi = mid - 1

    res = cnt[rr] - cnt[ll - 1]

    if ll != 1:
        res += min(cnt[ll - 1] - cnt[ll - 2], ranges[ll][0][0] - l)
    if rr != m:
        res += min(cnt[rr + 1] - cnt[rr], r - ranges[rr][0][1])

    return res


def getsm(l, r):
    global ranges, psa, m, n

    lo, hi = 1, m
    ll = 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if ranges[mid][0][0] >= l:
            hi = mid - 1
            ll = mid
        else:
            lo = mid + 1

    lo, hi = 1, m
    rr = 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if ranges[mid][0][1] <= r:
            lo = mid + 1
            rr = mid
        else:
            hi = mid - 1

    res = (psa[rr] - psa[ll - 1])

    if ll != 1 and ranges[ll - 1][1]:
        res = (res +
               ((fastpow(2, ranges[ll][0][0] - l) - 1) *
                fastpow(2, n - ranges[ll][0][0])))

    if rr != m and ranges[rr + 1][1]:
        res = (res +
               ((fastpow(2, r - ranges[rr][0][1]) - 1) *
                fastpow(2, n - r))) 
    return res


# main
n, m, q = map(int, input().split())

events = {}

for _ in range(m):
    l, r = map(int, input().split())
    events[l] = events.get(l, 0) ^ 1
    events[r + 1] = events.get(r + 1, 0) ^ 1

# convert to sorted list
events = sorted(events.items())

# ranges is 1-indexed
ranges = [None]

ind = 0
lastI = 1
cur = events[0][1] if events and events[0][0] == 1 else 0
last = cur

for pos, x in events:
    if pos == 1:
        continue

    cur ^= x

    if cur != last:
        ranges.append(((lastI, pos - 1), last))
        lastI = pos
        last = cur

m = len(ranges) - 1

# prefix count of ones
cnt = [0] * (m + 1)
for i in range(1, m + 1):
    length = ranges[i][0][1] - ranges[i][0][0] + 1
    cnt[i] = cnt[i - 1] + ranges[i][1] * length

# compute val
val = [0] * (m + 1)
pw = 0

for i in range(m, 0, -1):
    length = ranges[i][0][1] - ranges[i][0][0] + 1

    if ranges[i][1]:
        val[i] = ((fastpow(2, length) - 1) * fastpow(2, pw))

    pw = (pw + length)

# prefix sum of val
psa = [0] * (m + 1)
for i in range(1, m + 1):
    psa[i] = (psa[i - 1] + val[i])

# queries
for _ in range(q):
    l, r, k = map(int, input().split())

    if ones(l, r) >= k:
        print((fastpow(2, k) - 1) % MOD)
        continue

    lo, hi = l, r
    pos = l

    while lo <= hi:
        mid = (lo + hi) // 2
        if ones(l, mid) + (r - mid) >= k:
            lo = mid + 1
            pos = mid
        else:
            hi = mid - 1

    o = ones(l, pos)

    p1 = ((fastpow(2, o) - 1) * fastpow(2, k - o)) % MOD
    p2 = (getsm(pos + 1, r) *
          fastpow(fastpow(2, n - r), MOD - 2)) % MOD

    print((p1 + p2) % MOD)