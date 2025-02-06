#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")


using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], c[MAXN], q;

long long dp[MAXN][3], ans[MAXN];

pair<int,int> s[MAXN],queries[MAXN];

/*
dp[node][3]

0 is < than m
1 is equal to m
2 is > than m
*/

long long med(int x, int y, int z) {
	return x ^ y ^ z ^ min({x, y, z}) ^ max({x, y, z});
}



inline void update(int node, int m){

    for(int i = 0; i < 3; i++) dp[node][i] = 1e18;

    if((node<<1) > n){

        for(int i = 0; i < 3; i++) dp[node][i] = c[node];

        if(a[node] < m) dp[node][0] = 0;
        if(a[node] == m) dp[node][1] = 0;
        if(a[node] > m) dp[node][2] = 0;
        return;
    }

    int lc = node<<1;
    int rc = node<<1|1;

    int cost[3] = {(a[node] >= m) * c[node], (a[node] != m) * c[node], (a[node] <= m) * c[node]};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){

                dp[node][med(i,j,k)] = min(dp[node][med(i,j,k)], dp[lc][j] + dp[rc][k] + cost[i]);
            }
        }
    }

}

int main(){

    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        s[i] = {a[i], i};
    }

    sort(s+1, s+n+1);

    for(int i = n; i >= 1; i--) update(i, 0);

    cin >> q;

    for(int i = 1; i <= q; i++){
        int x; cin >> x;
        queries[i] = {x,i};
    }

    sort(queries+1, queries+q+1);

    
    int p = 1;
    
    for(int j = 1; j <= q; j++){

        auto [x, ind] = queries[j];       

        while(p <= n && s[p].first < x){
            
            int cur = s[p].second;
            while(cur >= 1){
                update(cur, x);
                cur >>=1;
            }

            p++;
        }

        for(int i = p; s[i].first == x; i++){
            int cur = s[i].second;
            while(cur >= 1){
                update(cur, x);
                cur >>=1;
            }
        }

        ans[ind] = dp[1][1];
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << "\n";

    




    


    


    
}