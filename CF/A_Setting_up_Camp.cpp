#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c; cin >> a >> b >> c;

        long long ans = 0;
        int res = b%3;


        if(res + c >= 3 || !res) cout << a + (int)ceil((b+c)/3.0) << "\n";
        else cout << "-1\n";

        
    }
}