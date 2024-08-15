#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long 
//make all things odd
//in one operation we choose two numbers and paint the minimum odd
//choose a smaller even number 
//we should always choose max odd number

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> e;

        int mx = 0;

        bool flag = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];

            flag &= (a[i]%2 == a[0]%2);

            if(a[i] &  1) mx = max(mx, a[i]);
            else e.push_back(a[i]);
        }

        if(flag){
            cout << "0\n";
            continue;
        }

        sort(e.begin(), e.end());

        int ans = 0;

        for(int i : e){
            if(mx < i){
                mx += e.back();
                ans++;
            }
            mx += i;
            ans++;
        }

        cout << ans << "\n";
    }
}