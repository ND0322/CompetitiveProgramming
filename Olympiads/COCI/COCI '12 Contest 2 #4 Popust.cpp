#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int n;

pair<int,int> a[MAXN];

set<pair<int,int>> suf;
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i].second >> a[i].first;

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) suf.insert({a[i].second, i});
    
    int mn = 1e9;
    long long psa = 0;


    for(int i = 1; i <= n; i++){
        long long ans = psa;

        suf.erase({a[i].second, i});
        mn = min(mn, a[i].second - a[i].first);


        if(i == n){
            cout << psa + a[i].first + mn << "\n";
            continue;
        }

        cout << ans + min((*suf.begin()).first, mn + a[i].first) << "\n";

        psa += a[i].first;
    }
}