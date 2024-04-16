#include <bits/stdc++.h>
#include <iostream>
#include <map>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

const int MAXN = 2e5+5;
const int MAXM = 1e6+5;

int n, m, k, a[MAXN];

map<int,int> req, freq;


//template sliding window question

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        req.clear();
        freq.clear();
        cin >> n >> m >> k;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1;i <= m; i++){
            int x; cin >> x;
            req[x]++;
        }

        int cnt = 0;
        int ans = 0;
        for(int i = 1; i < m; i++){
            cnt += (freq[a[i]] < req[a[i]]);
            freq[a[i]]++;
        }
        
        for(int i = m; i <= n; i++){
            cnt += (freq[a[i]] < req[a[i]]);
            
            freq[a[i]]++;
            if(cnt >= k) ans++;
            freq[a[i-m+1]]--;
            cnt -= freq[a[i-m+1]] < req[a[i-m+1]];
        }

        cout << ans << "\n";
    }
}