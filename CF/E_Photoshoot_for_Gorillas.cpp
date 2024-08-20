#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m,k; cin >> n >> m >> k;

        vector<long long> pos;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) pos.push_back((min(i,n-k+1)-max(1,i-k+1)+1)*(min(j,m-k+1)-max(1,j-k+1)+1));
        }

        sort(pos.rbegin(), pos.rend());
        int w; cin >> w;

        vector<long long> g(w);

        for(int i = 0; i < w; i++) cin >> g[i];

        sort(g.rbegin(), g.rend());

        long long ans = 0;
        for(int i = 0; i < min(n*m, w); i++) ans += pos[i] * g[i];
        cout << ans << "\n";
    }
    


}