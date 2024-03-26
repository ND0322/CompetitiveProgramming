#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c,d; cin >> a >> b >> c >> d;

        if(!(a+b+c+d)) cout << "0\n";
        else if(a+b+c+d == 1 || a+b+c+d == 2 || a+b+c+d == 3) cout << "1\n";
        else cout << "2\n";
        
    }
}