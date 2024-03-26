#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, psa[MAXN][2], tot[2], psa2[MAXN][2], a[MAXN];

bool color[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        char c; cin >> c;

        psa[i][0] = psa[i-1][0];
        psa[i][1] = psa[i-1][1];

        color[i] = c == 'G';

        psa[i][c == 'G']++;

        if(c == 'G') tot[1]++;
        else tot[0]++;
    }

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i] = x;
        psa2[i][0] = psa2[i-1][0];
        psa2[i][1] = psa2[i-1][1];
        if(psa[x][color[i]] - psa[i-1][color[i]] == tot[color[i]]) psa2[i][color[i]]++;
        

        

    }

    //for(int i = 1; i <= n; i++) cout << psa2[i][0] << " ";
    //cout << "\n";

    //for(int i = 1; i <= n; i++) cout << psa2[i][1] << " ";
    //cout << "\n";

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        if(psa[a[i]][color[i]] - psa[i-1][color[i]] != tot[color[i]]) ans += psa2[a[i]][!color[i]] - psa2[i-1][!color[i]];
        else ans += psa2[n][!color[i]]-psa2[i-1][!color[i]];
            
    
       
        //cout << ans << "\n";
    }

    cout << ans << "\n";
}