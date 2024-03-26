#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, x; cin >> n >> x;

        int ans = 0;

        int last = 0;
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            ans = max(ans,c-last);
            last = c;
        }
        ans = max(ans, 2*(x-last));

        cout << ans << "\n";
    }
}