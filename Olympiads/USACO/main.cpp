#include <bits/stdc++.h>
#include <iostream>
#include <set>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

using namespace std;

/*
upperbound is min ai / 4
1 2 3 are always possible
*/

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int n; cin >> n;

    set<int> s; 

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        s.insert(x);
    }

    long long sm = 0;
    for(int i = 1; i <= *s.begin()/4; i++){
        set<int> f;

        for(int j : s){
            f.insert(j % i);
            if(f.size() > 3) break;
        }

        if(f.size() <= 3) sm += i;
    }

    cout << sm << "\n";

}