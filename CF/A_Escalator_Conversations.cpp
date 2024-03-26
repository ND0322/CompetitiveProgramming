#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main(){
    int tt ; cin >> tt;

    while(tt--){
        int n,m,k,h; cin >> n >> m >> k >> h;

        

        int ans = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(abs(x-h) % k == 0 && abs(x-h)/k < m && x != h){
                //cout << x << endl;
                ans++;
            }
        }

        cout << ans << "\n";
        
    }
}