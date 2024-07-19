#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

const int MAXN = 1e6+5;

int n, a[MAXN], b[MAXN], tin[MAXN], tout[MAXN];

stack<int> st[MAXN];


bool can(int x){
    set<pair<int,int>> sts; 
    for(int i = 1; i <= x; i++){
        while(st[i].size()) st[i].pop();
        st[i].push(0);
        sts.insert({0,i});
    }

    stack<int> aa;

    for(int i = n; i >= 1; i--){
        aa.push(a[i]);
        tout[i] = -1;
    }
    //min time in b

    //largest time such that i > time 
    //largest element less than i
    for(int i = 1; i <= n; i++){
        if(tout[b[i]] != -1){
            if(st[tout[b[i]]].top() != b[i]) return 0;
            continue;
        }
        do{
            int t = tin[aa.top()];

            cout << t << "\n";

            auto it = sts.lower_bound({t,-1});

            if(it == sts.begin()) return 0;
            it--;            

            int tt = (*it).first;
            int pos = (*it).second;
            

        
            sts.erase({tt, pos});
            st[pos].push(t);
            tout[aa.top()] = pos;
            sts.insert({t, pos});

            

            aa.pop();
        }
        while(aa.size() && aa.top() != b[i]);

        for(int i = 1; i <= x; i++){
            cout << i << " " << st[i].top() << "\n";
        }
    }

    return 1;    
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        cin >> b[i];
        tin[b[i]] = i;
    }



    cout << can(5) << "\n";

    /*
     int lo = 1;
    int hi = n;
    int ans = n;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(can(mid)){
            hi = mid-1;
            ans = mid;
        }
        else lo = mid+1;
    }

    cout << ans << "\n";
    */

   
}