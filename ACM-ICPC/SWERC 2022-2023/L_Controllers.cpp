#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int n; cin >> n;

    int cnt[2] = {0,0};

    string s; cin >> s;

    for(int i = 0; i < n; i++) cnt[s[i] == '+']++;

    int q; cin >> q;

    while(q--){
        int x,y; cin >> x >> y;
        if(cnt[0] == cnt[1]){
            cout << "YES\n";
            continue;
        }

        if(x == y){
            cout << "NO\n";
            continue;
        }

        //ax - bx + (cnt[1] - a)y - (cnt[0] - b)y
        //let k = a-b

        //kx + (cnt[1] - cnt[0] - k)y = 0
        //k(y-x) = (cnt[1] - cnt[0])y
        //k = (cnt[1] - cnt[0])y/(y-x)
        //just check k

        if(((cnt[1] - cnt[0]) * y) % (y-x)){
            cout << "NO\n";
            continue;
        }

        int k = (cnt[1] - cnt[0]) * y / (y-x);

        cout << (k >= -cnt[0] && k <= cnt[1] ? "YES\n" : "NO\n");

    }
}