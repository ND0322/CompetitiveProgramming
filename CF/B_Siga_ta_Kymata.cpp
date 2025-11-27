#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<bool> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            b[i] = (c == '1');
        }

        if(b[1] || b[n]){

            cout << "-1\n";
            continue;
        }

        int posa = 0;
        int posb = 0;

        for(int i = 1; i <= n; i++){
            if(a[i] == 1) posa = i;
            if(a[i] == n) posb = i;
        }

        vector<pair<int,int>> ans;
        ans.push_back({1, posa});
        ans.push_back({1, posb});
        ans.push_back({posa, n});
        ans.push_back({posb, n});
        ans.push_back({min(posa, posb), max(posa, posb)});
        vector<bool> c(n+1);
        for(auto [l,r] : ans){
            for(int i = min(l, r) +1; i < max(l,r); i++){
                if(a[i] > min(a[l], a[r]) && a[i] < max(a[l], a[r])) c[i] = 1;
            }
        }

        bool flag = 1;
 
        for(int i = 1; i <= n; i++){
            if(!b[i]) continue;
 
            flag &= c[i];
        }
 
        if(flag){
            cout << ans.size() << "\n";
            for(auto [l,r] : ans) cout << min(l, r) << " " << max(l,r) << "\n";
        }
        else cout << "-1\n";



        
    }
}