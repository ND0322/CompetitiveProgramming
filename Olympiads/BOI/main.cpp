#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;


int n,m,k, a[MAXN], b[MAXN];

/*
sub 2 -> iterate all masks 

n * k - min(n, b[i])
*/
int main(){
    cin >> n >> m >> k;

    int sm = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sm += a[i];
    }
    for(int i = 1; i <= m; i++) cin >> b[i];


    if(m < k){
        cout << "Impossible\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        if(a[i] < k){
            cout << "Impossible\n";
            return 0;
        }
    }

    

    int ans = 1e9;

    for(int i = 0; i < (1<<m); i++){
        vector<int> c;

        for(int j = 0; j < m; j++){
            if(i & (1<<j)) c.push_back(b[j+1]);
        }

        int tot = 0;

        for(int j : c) tot += j;

        if(tot < sm) continue;

        int cap = n * k;

        for(int j : c) cap -= min(n, j);

        if(cap <= 0) ans = min(ans, tot - sm);
    }

    if(ans == 1e9) cout << "Impossible\n";
    else cout << ans << "\n";
}