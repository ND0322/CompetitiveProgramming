#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;
    while(tt--){
        
        int n,a,b; cin >> n >> a >> b;


        if(a == 1){
            cout << (!((n-1)%b) ? "Yes\n" : "No\n");
            continue;
        }

        int t = 1;
        bool ans = 0;

        while(t <= n){
            if(t%b == n%b){
                cout << "Yes\n";
                ans = 1;
                break;
            }

            t *= a;
        }

        if(!ans) cout << "No\n";
    }

    


}