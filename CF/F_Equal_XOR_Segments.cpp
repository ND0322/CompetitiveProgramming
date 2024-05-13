#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>


using namespace std;

const int MAXN = 2e5+5;

int n, q, p[MAXN];



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        map<int,set<int>> mp;

        mp[0].insert(0);

        for(int i = 1; i <= n; i++){
            cin >> p[i];
            p[i] ^= p[i-1];
            mp[p[i]].insert(i);
        }

        while(q--){
            int l,r; cin >> l >> r;

            //case 1: two segments
            if(p[l-1] == p[r]){
                cout << "YES\n";
                continue;
            }

            int i = *mp[p[r]].lower_bound(l);
            int j = *--mp[p[l-1]].lower_bound(r);

            cout << (i < j ? "YES\n" : "NO\n");
        }

        cout << "\n";
    }
}

