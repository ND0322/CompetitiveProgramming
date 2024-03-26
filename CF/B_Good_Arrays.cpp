#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);
        set<int> c;

        long long ans = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];

            ans += a[i];
            c.insert(a[i]);
        }

        if(n == 1){
            cout << "NO\n";
            continue;
        }

        
        if(c.size() == n){
            cout << "YES\n";
            continue;
        }
        

        if(ans > 2*n){
            cout << "YES\n";
       }
        else{
            cout << "NO\n";
       }

        



        
    }
}