#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int near(int x, int k){
    return ceil(x/(float) k) * k;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        int ans = 1e9;
        int tot = 1;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            ans = min(ans,near(x,k)-x);
            if(k == 4) tot = (tot * x) % 4;
                
            
        }

        //cout << "t" << tot << "\n";

        
        if(k == 4){
            if(tot == 0){
                cout << "0\n";
            }
            if(tot&1){
                cout << min(ans,2) << "\n";
            }
            if(tot == 2){
                cout << min(ans,1) << "\n";
            }
        }
        else cout << ans << "\n";

        


    }
}