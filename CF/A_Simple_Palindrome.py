for _ in range(int(input())):

    n = int(input())
    a = ['a', 'e', 'i', 'o', 'u']

    ans = ''

    for i in range(5):
        ans += (n//5 + (n%5 > i)) * a[i]

    print(ans)

