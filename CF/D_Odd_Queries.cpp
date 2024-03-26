#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    //approach: get sum of whole thing. for each query, subtract prefirx sum from total, then add r-l * k and check if odd

    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;

        vector<ll> psa(n+1);
        psa[0] = 0;
        ll tot = 0;

        for(int i = 1; i <= n; i++){
            

            
            int x; cin >> x;
            psa[i] = psa[i-1] + x;
            tot += x;
            
        }

        while(q--){
            int l,r,k; cin >> l >> r >> k;

            ll temp = psa[n]-(psa[r]-psa[l-1])+k*(r-l+1);

            



            if(temp % 2 == 0){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }

        }
    }
    
}