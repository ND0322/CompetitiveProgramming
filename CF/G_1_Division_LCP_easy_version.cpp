#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, l, r, z[MAXN];

string s;

//bsearch and max to the first prefix
//greedy

void zfun() {
    int l = 0;
    int r = 0;
    for(int i = 1; i < n; i++){
        if(i < r) z[i] = min(r - i, z[i - l]);
    
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
}




bool can(int x){
    set<int> pos;

    for(int i = 0; i <n ; i++){
        if(z[i] >= x) pos.insert(i);
    }

    int p = -1;

    int ans = 0;

    while(1){
        auto it = pos.lower_bound(p);
        if(it == pos.end()) return ans+1 >= l;
        p = *it + x;
        ans++;
    }
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> l >> r;

        cin >> s;

        memset(z, 0, sizeof(z));


        zfun();        

        
        int lo = 1;
        int hi = n;
        int ans = 0;
        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(can(mid)){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }

        cout << ans << "\n";
        
        
    }
}