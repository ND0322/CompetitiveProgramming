#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 2e5+5;

int n, q, row[MAXN], col[MAXN];

map<pair<int,int>,int> upd;

int main(){
    cin >> n >> q;

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int x,y; cin >> x >> y;

            row[x]++;
            col[y]++;

            upd[{x,y}]++;
        }
        else{
            int x,y; cin >> x >> y;

            cout << ((row[x] + col[y] - upd[{x,y}])&1) << "\n";
        }
    }


}


