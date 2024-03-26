for _ in range(int(input())):
    n = int(input())

    arr = list(map(int,input().split(" ")))
    ans = []


    for i in arr:
        ans.append(str(n-i+1))


    print(" ".join(ans))