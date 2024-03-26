def isvowel(c):
    if(c == "a" or c == 'e'):
        return True

    return False

for _ in range(int(input())):

    n = int(input())

    s = input()

    i = n-1

    ans = ""
    while(i >= 0):
        if isvowel(s[i]) and not isvowel(s[i-1]):
            ans += s[i]
            ans += s[i-1]
            ans += "."
            i-=2
            continue

        ans += s[i]
        i-=1
    
    print(ans[:len(ans)-1][::-1])

