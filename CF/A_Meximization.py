for _ in range(int(input())):
    n = int(input())
    l = sorted(input().split(" "))

    added = set()

    ans = []
    suf = []

    for i in l:
        if(i not in added):
            added.add(i)
            ans.append(i)
        else:
            suf.append(i)

    ans.extend(suf)
    

    print(" ".join(ans))