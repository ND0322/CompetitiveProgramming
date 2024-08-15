#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int ans[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, x,y; cin >> n >> x >> y;

        for(int i = y; i <= x; i++) ans[i] = 1;
        for(int i = x+1; i <= n; i+=2) ans[i] = -1;
        for(int i = x+2; i <= n; i+=2) ans[i] = 1;
        for(int i = y-1; i >= 1; i-=2) ans[i] = -1;
        for(int i = y-2; i >= 1; i-=2) ans[i] = 1;

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";

        
    }
}