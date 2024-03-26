n = int(input())
l = list(input())
if l.count("F") == n:
	l[0] = "E"

positions = [i for i in range(n) if l[i] != "F"]
ones = positions[0] + n - 1 - positions[-1]
mn, mx = 0, 0
for x, y in zip(positions, positions[1:]):
	mn += ((y - x) & 1) ^ (l[x] != l[y])
	mx += y - x - (l[x] != l[y])
ans = range(mn, ones + mx + 1, 1 + (ones == 0))
print(len(ans))
for level in ans:
	print(level)