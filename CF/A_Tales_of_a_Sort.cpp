#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i ++){
            cin >> a[i];
        }

        int ans = 0;

        vector<int> b(a);

        sort(a.begin(),a.end());

        for(int i = 0; i < n; i++){
            if(b[i] != a[i]){
                ans = max(ans,b[i]);
            }
        }

        cout << ans << "\n";
    }
}
