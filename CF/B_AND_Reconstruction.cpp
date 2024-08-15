#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;
    
    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n-1; i++) cin >> a[i];

        a.push_back(a[n-2]);

        int cur = a[0];
        vector<int> ans = {cur};

        for(int i = 0; i < n-1; i++){
            ans.push_back(a[i] | a[i+1]);
        }

        bool flag = 1;
        for(int i = 0; i < n-1; i++){
            if((ans[i] & ans[i+1]) != a[i]) flag = 0;
        }

        if(!flag){
            cout << "-1\n";
            continue;
        }

        for(int i : ans) cout << i << " ";
        cout << "\n";




    }
}