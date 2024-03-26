#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,psa[MAXN];

string s;

int main(){
    cin >> s;
    n = s.size();

    for(int i = 1; i <= n; i++){
        if(s[i-1] == 'C') psa[i] = 1;
        if(s[i-1] == 'O') psa[i] = 2;
        if(s[i-1] == 'W') psa[i] = 3;

        psa[i] ^= psa[i-1];
    }

    int q; cin >> q;

    while(q--){
        int l, r; cin >> l >> r;

        cout << ((psa[r] ^ psa[l-1]) == 1 ? "Y" : "N");
    }

    cout << "\n";
}