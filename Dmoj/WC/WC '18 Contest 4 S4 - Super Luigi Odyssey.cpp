#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


//just try to farm partials

//sub 1
//directly simulate for each query/update thingy

//sub 2
//lava increase thing is just update all nodes with h < that to 0
//queries are find the kth element to the right in sorted

const int MAXN = 3e5+5;
const int MOD = 1e9+7;

int n,q, a[MAXN], h[MAXN], k;

pair<int,int> p[MAXN];


int32_t main(){
    cin >> n >> q >> k;


    for(int i = 1; i <= n; i++){
        cin >> a[i] >> h[i];

        p[i] = {a[i], h[i]};
    }

    sort(p+1, p+n+1);
    


    int pos = 0;
    int cur = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(p[i].first == a[1]) pos = i;
    }

    //cout << pos << "\n";


    while(q--){
        int t; cin >> t;

        //cout << pos << " " << p[pos].first << " " << cur << "\n";
        
        if(t == 1){
            int x; cin >> x;
            cur += x;

            if(cur >= a[pos].second){
                cout << "-1\n";
                return 0;
            }
        }
        if(t==2){
            int x; cin >> x;

            //xth right platform for later

            while(x--){
                bool flag = 1;
                for(int i = pos-1; i >= 1; i--){
                    if(p[i].second > cur){
                        ans = (ans + (p[pos].first - p[i].first) % MOD) % MOD;
                        pos = i;
                        flag = 0;
                        break;
                    }
                }

                //cout << pos << "\n";

                if(flag){
                    cout << "-1\n";
                    return 0;
                }
            }

            
        }
        if(t == 3){
            int x; cin >> x;

            while(x--){
                bool flag = 1;
                for(int i = pos+1; i <= n; i++){
                    if(p[i].second > cur){
                        ans = (ans + (p[i].first - p[pos].first) % MOD) % MOD;
                        pos = i;
                        flag = 0;
                        break;
                    }
                }

                

                if(flag){
                    cout << "-1\n";
                    return 0;
                }
            }

            


        }
    }

    
    cout << ans%MOD << "\n";

}