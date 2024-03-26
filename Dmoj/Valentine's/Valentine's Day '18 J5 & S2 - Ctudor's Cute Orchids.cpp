#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m, a[15], deal[15][15], c[15], cd[15], tmp[15];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> c[i];

    for(int i = 0; i < m; i++){
        cin >> cd[i];

        for(int j = 0; j < n; j++) cin >> deal[i][j];
    }

    for(int i = 0; i < n; i++) cin >> a[i];

    long long ans = 1e9;

    for(int i = 0; i < (1<<m); i++){
        for(int j = 0; j < n; j++) tmp[j] = a[j];

        long long cost = 0;

        for(int j = 0; j < m; j++){
            if(i & (1<<j)){
                cost += cd[j];
                for(int k = 0; k < n; k++) tmp[k] -= deal[j][k];
            }
        }
        
        bool flag = 1;

        for(int j = 0; j < n; j++){
            if(tmp[j] < 0){
                flag = 0;
                break;
            }
            
            cost += tmp[j] * c[j];
        }
        
        if(flag) ans = min(ans,cost);
    }

    cout << ans << "\n";
}