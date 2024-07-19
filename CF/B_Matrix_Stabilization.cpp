#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<vector<int>> a(n+2, vector<int>(m+2,0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) cin >> a[i][j];
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] > max({a[i+1][j], a[i-1][j], a[i][j+1], a[i][j-1]})) cout << max({a[i+1][j], a[i-1][j], a[i][j+1], a[i][j-1]}) << " ";
                else cout << a[i][j] << " ";
            }
            cout << "\n";
            
        }

        
    }
}