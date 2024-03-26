#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 3e5+5;

int n, m, a[MAXN][10];

pair<int,int> ans;

bool can(int x){
    set<int> s;
    int rep[1<<m];

    for(int i = 1; i <= n; i++){
        int cnt = 0;

        for(int j = 0; j < m; j++) cnt |= ((a[i][j] >= x) << j);
        s.insert(cnt);
        rep[cnt] = i;
    }

    vector<int> b;

    for(int i : s) b.push_back(i);

    for(int i = 0; i < b.size(); i++){
        for(int j = i; j < b.size(); j++){
            if((b[i] | b[j]) == ((1<<m)-1)){
                ans.first = rep[b[i]];
                ans.second = rep[b[j]];
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    int lo = 0;
    int hi = 1e9;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)) lo = mid+1;
        else hi = mid-1;
    }

    cout << ans.first << " " << ans.second << "\n";
}