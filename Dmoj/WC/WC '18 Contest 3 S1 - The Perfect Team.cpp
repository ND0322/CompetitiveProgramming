#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, k, m;

pair<int,int> t[MAXN];
pair<int,int> a[MAXN];
bool used[MAXN];

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;

        t[a[i].first] = max(t[a[i].first], {a[i].second, i});
    }

    long long ans = 0;

    for(int i = 1; i <= k; i++){
        ans += t[i].first;
        used[t[i].second] = 1;
    }

    vector<int> opt;

    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        opt.push_back(a[i].second);
    }

    sort(opt.rbegin(), opt.rend());

    for(int i = 0; i < m-k; i++) ans += opt[i];
    cout << ans << "\n";
}