#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;



int n, m, a[MAXN], b[MAXN];

pair<int,int> c[MAXN];

bool can(int x){

    vector<int> times;
    vector<int> cnt(m+1, 0);

    for(int i = n; i >= 1; i--){
        if(cnt[c[i].second] == x) continue;
        cnt[c[i].second]++;
        times.push_back(c[i].first);
    }

    reverse(times.begin(), times.end());

    for(int i = 1; i <= m; i++){
        if(cnt[i] < x) return 0;
    }

    int cur = 0;
    for(int i : times){
        if(cur > i) return 0;
        cur++;
    }

    return 1;


    
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        if(m > n){
            cout << "0\n";
            continue;
        }

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        for(int i = 1; i <= n; i++) c[i] = {b[i], a[i]};

        sort(c+1,c+n+1);

    

        
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