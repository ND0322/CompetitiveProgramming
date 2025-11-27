#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e6+5;


//use ulimit -s unlimited

/*
the people who recieve shirts form some prefix
binary search? 
we know how many shirts each person needs 
*/


int n,m, a[MAXN], b[MAXN];
vector<int> level;
map<int,int> mp;

bool can(int x){
    //can we do it given that we are going up to color x 


    set<int> s;

    int tmp = x;
    int sm = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < mp[x]) break;
    
        cnt++;        
        if(a[i] != a[i+1]){
            sm = cnt;
            s.insert(cnt);
            tmp--;
        }
    }

    s.insert(cnt);

    for(int i = m; i >= 1; i--){
        if(s.empty()) break;
        auto it = s.lower_bound(b[i]);

        //all levels have less than b[i] -> erase the biggest level
        if(it == s.end()){
            s.erase(prev(s.end()));
            continue;
        }

        if(b[i] == *it){
            s.erase(it);
            continue;
        }

        if(it == s.begin()){
            int nw = *it - b[i];
            s.erase(it);
            s.insert(nw);
            continue;
        }

        auto it2 = it;
        it2--;

        int nw = *it2 + *it - b[i];
        s.erase(it);
        s.erase(it2);
        s.insert(nw);
    }
    
    return s.empty();
}

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> n >> m;

        mp.clear();
        level.clear();

        a[n+1] = 0;
        b[m+1] = 0;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) cin >> b[i];

        sort(a+1, a+n+1);
        reverse(a+1,a+n+1);
        sort(b+1,b+m+1);
        //reverse(b+1, b+m+1);

        int cur = 1;
        
        for(int i = 1; i <= n; i++){
            mp[cur] = a[i];

            if(a[i] != a[i+1]) cur++;
            
        }

        int lo = 1;
        int hi = cur;

        int ans = 0;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(can(mid)){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }

        //cout << ans << " " << mp[ans] << "\n";

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] < mp[ans]) break;
            cnt++;
        }

        if(!ans) cnt = 0;
       

        cout << "Case #" << _ << ": " << cnt << "\n";
    }
}