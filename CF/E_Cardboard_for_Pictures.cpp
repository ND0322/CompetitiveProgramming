#include <bits/stdc++.h>
#include <iostream>

#define int long long

using namespace std;

const int MAXN = 2e5+5;

typedef long long ll;

int n;

ll c,a[MAXN];


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> c;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        //cout << can(124321725) << endl;

        ll lo = 0;
        ll hi = (ll)sqrt(c);
        //cout << hi <<endl;



        while(lo <= hi){
            ll mid = (lo+hi)/2;

            ll ans = 0;

            for(int i = 0; i < n; i++){
                ans += (a[i] + 2*mid) * (a[i] + 2*mid);

                if(ans > c){
                    hi = mid-1;
                    break;
                }
            }

           

            if(ans == c){
                cout << mid << "\n";
                break;
            }
            else if(ans < c){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }

            

           

            
            
        }

    }


}