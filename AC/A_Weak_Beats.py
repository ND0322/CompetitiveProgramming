def solve():

    s = input()

    for i in range(1,17,2):
       
        if(s[i] != "0"):
            print("No")
            return 
    
    print("Yes")

solve()