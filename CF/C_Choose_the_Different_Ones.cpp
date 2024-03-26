#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

void solve(){
    int n,m,k; cin >> n >> m >> k;


    set<int> a;
    set<int> b;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        a.insert(x);
    }
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        b.insert(x);
    }

    int cnta = 0;
    int cntb = 0;

    for(int i = 1; i <= k; i++){

        if(!b.count(i) && !a.count(i)){
            cout << "NO\n";
            return;
        }
        if(a.count(i) && !b.count(i)){
            if(cnta == k/2){
                cout << "NO\n";
                return;
            }
            cnta++;
        }

        if(b.count(i) && !a.count(i)){
            if(cntb == k/2){
                cout << "NO\n";
                return;
            }

            cntb++;
        }

        if(a.count(i) && b.count(i)){
            if(cnta == k/2 && cntb == k/2){
                cout << "NO\n";
                return;
            }

            if(cnta < cntb) cnta++;
            else cntb++;
        }
    }

    cout << "YES\n";

}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
        
    }
}