MOD = int(1e9 + 7)


def expo(base, pow):
    if pow == 0:
        return 1
    x = expo(base * base % MOD, pow // 2)
    return base * x % MOD if pow % 2 == 1 else x


n, q, c = map(int, input().split())

pairs_dict = {0: 0}
for i in range(q):
    a, h = map(int, input().split())
    pairs_dict[h] = min(a, pairs_dict.get(h, h))
pairs = sorted((a, h) for h, a in pairs_dict.items())
q = len(pairs_dict) - 1

print(pairs)

dp = [[0 for j in range(c + 1)] for i in range(q + 1)]
dp[0][0] = 1
for i in range(1, q + 1):
    gap1 = pairs[i][0] - pairs[i - 1][1]
    gap2 = pairs[i][1] - pairs[i][0] - 1
    pref_sum = 0
    for j in range(1, c + 1):
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] * expo(j - 1, gap1 + gap2) +
                    pref_sum * (expo(j - 1, gap1) - expo(j - 2, gap1)) * expo(j - 1, gap2)) % MOD
        pref_sum = (pref_sum + dp[i - 1][j - 1]) % MOD

print(sum(dp[q]) * expo(c, n - pairs[q][1]) % MOD)