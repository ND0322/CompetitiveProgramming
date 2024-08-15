#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a;
        bool flag = 1;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            flag &= (x == 0);
            a.push_back(x);
    
        }
        
        if(n == 1){
            cout << "1\n";
            cout << a[0] << "\n";
            continue;
        }
        if(flag){
            cout << "0\n";
            cout << "\n";
            continue;
        }
        

        int cur = (1<<29);

        vector<int> ans;

        while(cur){
            for(int i = 0; i < n; i++) a[i] = abs(a[i] - cur);
            ans.push_back(cur);
            cur >>=1;
        }

        flag = 1;

        for(int i = 0; i < n; i++){
            flag &= (a[i] == a[0]);
        }

        if(!flag){
            cout << "-1\n";
            continue;
        }

        ans.push_back(a[0]);
        cout << ans.size() << "\n";

        for(int i : ans) cout << i << " ";
        cout << "\n";

        

        
    }
}