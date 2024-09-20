s = input()
t = input()

k = int(input())

cnt = 0
flag = 1

for i in range(len(s)):
    cnt += (s[i] != t[i])

    if(s[i] == " " and t[i] != " "):
        flag = 0
    
    if(t[i] == " " and s[i] != " "):
        flag = 0


if(cnt > k or not flag):
    print("No plagiarism")
else:
    
    print("Plagiarized")