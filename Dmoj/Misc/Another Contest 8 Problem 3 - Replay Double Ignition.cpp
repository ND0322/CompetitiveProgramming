#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//it will repeat at some point

const int MAXN = 1e6+5;

int m,q;

int main(){
    cin >> m >> q;

    string s = "1";

    int a = 1;
    int b = 1;

    for(int i = 1; i <= MAXN; i++){
        int tmp = b;
        b += a;
        b %= m;
        a = tmp;

        if(a == 1 && b == 1) break;
        s += to_string(a);    
    }

    while(q--){
        long long x; cin >> x;

        x %= s.size();

        if(!x) cout << s[s.size()-1] << "\n";
        else cout << s[x-1] << "\n";
    }
}

