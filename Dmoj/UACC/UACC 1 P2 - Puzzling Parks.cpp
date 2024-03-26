#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    //2 and 3 are edge

    if(n == 2) cout << "1\n";
    else if(n==3) cout << "4\n";
    else if(n==4) cout << "5\n";
    else if(n==5) cout <<"6\n";
    
    else{
        int cnt = (n-2)/4 + (n-4)/4;
    

        cnt+=2;

        if((n-2) % 4 == 0) cout << cnt - 2 + n << "\n";
        if((n-2) % 4 == 1) cout << cnt + n << "\n";
        if((n-2)%4 == 2) cout << cnt + n -1 << "\n";
        if((n-2)%4 == 3) cout << cnt + n -1 << "\n";
    }


    




   
}

/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/