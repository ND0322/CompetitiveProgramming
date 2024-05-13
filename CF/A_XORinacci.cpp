#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//a b a^b a b a^b

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b, n; cin >> a >> b >> n;

        if(n % 3 == 0) cout << a << "\n";
        if(n% 3 == 1) cout << b << "\n";
        if(n%3 == 2) cout << (a^b) << "\n";
    }
}