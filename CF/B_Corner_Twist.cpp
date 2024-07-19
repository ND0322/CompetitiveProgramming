#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 505;

int a[MAXN][MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            for(int j = 1; j <= m; j++) a[i][j] = -s[j-1]-'0';
            
        }

        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            for(int j = 1; j <= m; j++){
                a[i][j] += s[j-1]-'0';
                a[i][j] = (a[i][j] + 3) % 3;
            }
        }

        bool ans = 1;

        for(int i = 1; i <= n; i++){
            int sm = 0;

            for(int j = 1; j <= m; j++) sm = (sm+a[i][j])%3;
            ans &= !sm;
        }

        for(int j = 1; j <= m; j++){
            int sm = 0;

            for(int i = 1; i <= n; i++) sm = (sm+a[i][j])%3;
            ans &= !sm;
        }

        cout << (ans ? "YES\n" : "NO\n");
        
        
    }
}