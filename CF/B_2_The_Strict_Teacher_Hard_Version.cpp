#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

//r-l/2 if not edged other wise just r-l

int main(){
    int tt; cin >> tt;

    while(tt--){

        int n, m, q; cin >> n >> m >> q;

        set<int> s;

        s.insert(1);

        bool has[2] = {0,0};

        while(m--){
            int x; cin >> x;

            if(x == 1) has[0] = 1;
            if(x == n) has[1] = 1;

            s.insert(x);
        }


        while(q--){
            int x; cin >> x;

            auto it = s.lower_bound(x+1);

            int r = ((it == s.end()) ? n : *it);
            it--;


            if(r == n && !has[1]){
                cout << r-*it << "\n";
                continue;
            }

            if(*it == 1 && !has[0]){
                cout << r-*it << "\n";
                continue;
            }

            cout << (r-*it)/2 << "\n";

        }

    }
}
