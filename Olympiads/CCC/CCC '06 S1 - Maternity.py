def check(s):
    ans = True

    for i in range(5):
        
        
        
        if(ord(s[i]) in range(ord("A"),ord("E")+1)):
        
           
            ans = (ord(mt[i*2]) in range(ord("A"),ord("E")+1)) or (ord(mt[i*2+1]) in range(ord("A"),ord("E")+1)) or (ord(ft[i*2]) in range(ord("A"),ord("E")+1)) or (ord(ft[i*2+1]) in range(ord("A"),ord("E")+1))

            
        else:
            ans = ((ord(mt[i*2]) in range(ord("a"),ord("e")+1)) or (ord(mt[i*2+1]) in range(ord("a"),ord("e")+1))) and ((ord(ft[i*2]) in range(ord("a"),ord("e")+1)) or (ord(ft[i*2+1]) in range(ord("a"),ord("e")+1)))
            
        
        if(not ans): return False
    return True


mt = input()
ft = input()

for i in range(int(input())):
    if(check(input())):
        print("Possible baby.")
    else:
        print("Not their baby!")