#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;


const int MAXN = 105;

int n;

pair<long long,long long> a[MAXN];

unordered_map<int,set<int>> x;
unordered_map<int,set<int>> y;

int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;

        x[a[i].first].insert(a[i].second);
        y[a[i].second].insert(a[i].first);
    }
    
    long long ans = 0;

    for(int i = 0; i < n ; i++){
        long long bb = 0;
        long long bh = 0;
        for(int j : x[a[i].first]) bb = max(bb, abs(j - a[i].second));
        for(int j : y[a[i].second]) bh = max(bh, abs(j - a[i].first));

        ans = max(ans, bb * bh);
    }

    cout << ans << "\n";

    


}