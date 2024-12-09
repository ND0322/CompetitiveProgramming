for _ in range(int(input())):
    s = input()

    a = int(s[0])
    b = int(s[2])

    if(a == b):
        print(str(a) + '=' + str(b))
        continue

    if(a < b):
        print(str(a) + '<' + str(b))
        continue

    print(str(a) + '>' + str(b))