#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, grid[MAXN][MAXN];

long long ans[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cin >> grid[i][j];
        }

        fill(ans, ans + n+1, (1<<30)-1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    ans[i] &= grid[i][j];
                    ans[j] &= grid[i][j];
                }
                
            }
        }

        bool flag = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && grid[i][j] != (ans[i] | ans[j])){
                    flag = 0;
                }
            }
        }

    if(!flag){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}