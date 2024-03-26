#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 3e5+5;

int n, q, a[MAXN], psa[MAXN];

string s;

int main(){
    cin >> n >> q;

    cin >> s;

    for(int i =1; i < n; i++) if(s[i] == s[i-1]) a[i] = 1;
    for(int i = 1; i < n; i++) psa[i] = psa[i-1] + a[i];

    while(q--){
        int l, r;

        cin >> l >> r;

        cout << psa[r-1] - psa[l-1] << "\n";
    }
}

