#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, a[MAXN];

bool f(int x){
    //some stuff

    x = x * (x+1) / 2;

    int b = n;
    int r = -1;

    set<int> s;

    for(int i = 1; i <= n; i++){
        if(a[i] > x) break;
        
        s.insert(a[i]);
        r = a[i];
        b--;
    }

    if(!b) return 1;
    if(n * (n+1) <= 2*x) return 1;


    for(int a = 0; a <= n; a++){
        if((a+b) * (a+b+1) > 2 * x) continue;


        int cur = a + b;
        int last = a+b;
        int cnt = 0;
       
        int i = 0;

        while(cnt < a){
            auto it = s.lower_bound(cur);

            if(it == s.end()) break;
            cur += --last;
            cnt++;
        }

        if(cur <= r) continue;
        if(cnt >= a) return 1; 
    }
    return 0;
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;


        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a+1, a+n+1);


    
        int lo = 0;
        int hi = n;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(f(mid)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }

        cout << ans * (ans+1) / 2 << "\n";   
        
    
        
    }
}