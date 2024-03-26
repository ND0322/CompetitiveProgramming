#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n,q, psa[MAXN], last[MAXN];


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        //the only issue is when we land on a index within the block thats a copy
        //we have to do mod stuff to find the right number
        


        long long sz = 0;
        
        for(int i = 1; i <= n; i++){
            int t, x; cin >> t >> x;

            //cout << sz << "\n";

            if(t == 1){
                sz += 1;
                last[i] = x;
                psa[i] = sz;

            }
            else{
                last[i] = last[i-1];
                psa[i] = ((x+1) > 2e18/sz ? sz = 2e18 : sz *= (x+1));
                
            }
        }


        //for(int i = 1; i <= n; i++) cout << psa[i] << "\n";
        
      

        while(q--){
            long long x; cin >> x;

            while(1){
                int ans = lower_bound(psa + 1, psa + n + 1, x) - psa;

                if(psa[ans] == x){
                    cout << last[ans] << " ";
                    break;
                }

                if(x % psa[ans-1] == 0){
                    cout << last[ans-1] << " ";
                    break;
                }

                x %= psa[ans-1];
            }   
            
        }

        cout << "\n";
    }
}