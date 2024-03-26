#include <bits/stdc++.h>
#include <iostream>


using namespace std;

void solve(){
    int n; cin >> n;

        vector<int> p(n);

        for(int i = 0; i < n; i++){
            cin >> p[i];
        }

        sort(p.begin(),p.end());

       

        for(int i = 0; i <= n; i++){
            int ans = 0;

            for(int j:p){
                if(i < j){
                    ans++;
                }
            }

            if(ans == i){
                cout << ans << "\n";
                return;
            }
        }

        cout << -1 << "\n";

}

int main(){
    int t; cin >> t;
    while(t--){
        
        solve();
        
    }
}