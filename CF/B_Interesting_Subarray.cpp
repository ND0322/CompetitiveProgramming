#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        pair<int,int> ans = {-1, -1};

        for(int i = 1; i <= n-1; i++){
            if(abs(a[i] - a[i+1]) >= 2) ans = {i, i+1};
        }

        if(ans.first == -1){
            cout << "NO\n";
            continue;
        }
        else{
            cout << "YES\n";
            cout << ans.first << " " << ans.second << "\n";

        }
    }
}