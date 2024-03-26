#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, c, x,y; cin >> n >> c >> x >> y;

        vector<int> a(n+1);

        a[0] = 0;

        for(int i = 1; i <= n; i++) cin >> a[i];

        bool flag = 1;
        for(int i = 0; i < n; i++){
            c -= min((a[i+1] - a[i]) * x, y);
            if(c <= 0){
                flag = 0;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
        
        //compare (m[i+1] - m[i]) * a to 2 * b
    }
}