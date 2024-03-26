#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

int n, q;

set<int> id[MAXN];

//brute force over divisors and binary search to check if both are in range

void query(int l, int r, int x){
    //im an idiot and cant loop divisors
    for(int i = 1; i*i < x; i++){
        if(x % i == 0){
            if(id[i].lower_bound(l) != id[i].end() && *id[i].lower_bound(l) <= r && id[x/i].lower_bound(l) != id[x/i].end() && *id[x/i].lower_bound(l) <= r){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        id[x].insert(i);
    }

    while(q--){
        
        int l,r,x; cin >> l >> r >> x;

        query(l,r,x);
    }



}

