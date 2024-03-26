#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int n,m,a[MAXN];

pair<pair<int,int>,int> c[25];

pair<pair<int,int>,pair<int,int>> b[15];

int main(){
    cin >> n >> m;


    for(int i = 0; i < n; i++) cin >> c[i].first.first >> c[i].first.second >> c[i].second;
    for(int i = 0; i < m; i++) cin >> b[i].first.first >> b[i].first.second >> b[i].second.first >> b[i].second.second;

    int ans = 1e9;

    for(int i = 0; i < (1<<m); i++){
        memset(a,0,sizeof(a));
        int cur = 0;
        for(int j = 0; j < m; j++){
            if(i & (1<<j)){
                cur += b[j].second.second;
                for(int k = b[j].first.first; k <= b[j].first.second; k++) a[k] += b[j].second.first;
            }
        }

        bool flag = 1;

        for(int j = 0; j < n; j++){
            for(int k = c[j].first.first; k <= c[j].first.second; k++) flag &= (a[k] >= c[j].second);
        }
        if(flag) ans = min(ans,cur);
    }

    cout << ans << "\n";
    

}

