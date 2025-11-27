import sys
input = sys.stdin.readline

def find_min_p(k, y, hi):
    # find minimal p in [1..hi] such that p - p//y >= k
    lo = 1
    if lo - lo//y >= k:
        return lo
    # quick impossibility check
    if hi - hi//y < k:
        return None
    while lo < hi:
        mid = (lo + hi) // 2
        if mid - mid//y >= k:
            hi = mid
        else:
            lo = mid + 1
    return lo

def solve_case(x, y, k):
    N = 10**12
    # build lengths after each operation: L[0] = N, L[1], ..., L[x]
    L = [N]
    for _ in range(x):
        prev = L[-1]
        nxt = prev - prev // y
        L.append(nxt)
        # if it becomes zero, we can stop building further but keep zeros if needed
        if nxt == 0:
            # fill remaining with zeros (not strictly necessary)
            # but we'll keep lengths list length == x+1 for simplicity
            break
    # if we didn't reach x steps, append zeros
    while len(L) <= x:
        L.append(0)

    if L[x] < k:
        return -1

    cur_k = k
    # reverse from step x down to 1, using bounds L[j-1]
    for j in range(x, 0, -1):
        prev_len = L[j-1]
        p = find_min_p(cur_k, y, prev_len)
        if p is None:
            return -1
        cur_k = p

    return cur_k

def main():
    t = int(input().strip())
    out = []
    for _ in range(t):
        x, y, k = map(int, input().split())
        ans = solve_case(x, y, k)
        out.append(str(ans))
    print("\n".join(out))

if __name__ == "__main__":
    main()
