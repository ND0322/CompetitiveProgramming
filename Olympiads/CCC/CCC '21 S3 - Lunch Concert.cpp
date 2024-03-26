#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n,p[MAXN],w[MAXN],d[MAXN];

int f(int x){
    int ans = 0;

    for(int i = 0; i < n; i++){
        int cur;
        
       
        if(x >= p[i] - d[i] && x <= p[i] + d[i]) cur = 0;
        if(x < p[i] - d[i]) cur = p[i] - d[i] - x;
        if(x > p[i] + d[i]) cur = x - (p[i] + d[i]);

        ans += cur * w[i];
        
    }

    return ans;
}

bool can(int x){
    int res = f(x);
    if(f(x-1) > res && res < f(x+1)) return true;
    return false;
}

int32_t main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> p[i] >> w[i] >> d[i];

    
    int lo = 0;
    int hi = 1e9;


    while(lo <= hi){
        int mid = (lo+hi)/2;

        int l = f(mid-1);
        int r = f(mid+1);
        int x = f(mid);

        if(l >= x && r >= x){
            cout << x << "\n";
            return 0;
        }
        else if(l >= x && x >= r) lo = mid+1;
        else hi = mid-1;
    }
    

    

    
}