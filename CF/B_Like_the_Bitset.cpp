#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
each i is cover by at most k intervals

min(i, k) intervals 

from i-k to i

just greedy it?
*/

int main(){
    int tt; cin >> tt;


    while(tt--){
        int n,k; cin >> n >> k;

        vector<bool> a(n+1);

        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            a[i] = (c == '1');
        }

        int cnt = 0;


        for(int i = 1; i <= k-1; i++) cnt += a[i];

        bool flag = 1;

        for(int i = k; i <= n; i++){
            cnt += a[i];

            flag &= (cnt < k);

            cnt -= a[i-k+1];
        }

        if(!flag){
            cout << "NO\n";
            continue;
        }

        vector<int> ans(n+1);

        cout << "YES\n";
        int l = 1;
        int r = n;
        for(int i = 1; i <= n; i++){
            if(a[i]) ans[i] = l++;
            else ans[i] = r--;

            cout << ans[i] << " ";
        }

        cout << "\n";

        



        
    }
}