#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<int> cnt(m+1);

    for(int i = 1;  i<= n;i ++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;

            if(c == '1') cnt[j]++;
        }
    }

    vector<pair<int,int>> ans;

    for(int i = 1; i <= m; i++) ans.push_back({cnt[i], -i});

    sort(ans.rbegin(), ans.rend());

    for(int i = 0; i < m; i++) cout << -ans[i].second << (i < m-1 ? " " : "");
    cout << "\n";
}