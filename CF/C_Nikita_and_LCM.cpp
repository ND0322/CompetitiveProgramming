#include <bits/stdc++.h>
#include <iostream>
#include <set>

#define int long long

using namespace std;


const int MAXN = 2e5+5;

int n, a[MAXN];

long long gcd(long long a, long long b){
    return (!b ? a : gcd(b, a%b));
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

int32_t main(){
    int tt; cin >> tt;

    

    while(tt--){
        cin >> n;

        

        
        set<int> s;
        int l = 1;
        int m = 0;
        bool check = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            l = lcm(a[i], l);
       
            if(l > 1e9) check = 1;
            m = max(m, a[i]);

            s.insert(a[i]);
        }


        if(check){
            cout << n << "\n";
            continue;
        }

        bool flag = 0;
        for(int i = 1; i <= n; i++) flag |= (l == a[i]);

        if(!flag){
            cout << n << "\n";
            continue;
        }


        //each ai is a divisor of max

       


        int ans = 0;
        for(int i = 2; i <= sqrt(m); i++){

            if(m % i != 0 || s.find(i) != s.end()) continue;
            
            int j = 0;
            int cnt = 0;

            int cur = 1;
            while(j < n){

                bool found = 0;
                
                for(int k = j+1; k <= n; k++){
                    if(i % a[k] == 0){
                        j = k;
                        cnt++;
                        found = 1;
                        cur = lcm(cur, a[k]);
                        break;
                    }
                }

                if(!found) break;

               

                
            }

            //cout << i << " " << cnt << "\n";

            if(cur == i) ans = max(ans, cnt);
        }

        for(int i = 2; i <= sqrt(m); i++){

            if(m % i != 0 || s.find(m/i) != s.end()) continue;
            
            int j = 0;
            int cnt = 0;

            int cur = 1;
            while(j < n){

                bool found = 0;
                
                for(int k = j+1; k <= n; k++){


                    if((m/i) % a[k] == 0){

                        
                        j = k;
                        cnt++;
                        found = 1;
                        cur = lcm(cur, a[k]);
                        break;
                    }
                }

                if(!found) break;

                
            }


            
            if(cur == m/i) ans = max(ans, cnt);
        }

        

        cout << ans << "\n";


    
    }
}