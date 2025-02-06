#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int fact[MAXN];

int32_t main(){
    int tt; cin >> tt;

    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i;
    

    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> ans = {1};

        if(n >= 3 || k == 3 || k == 6 || k == 9) ans.push_back(3);
        if(k == 5) ans.push_back(5);

        if(k == 7 || n >= 3) ans.push_back(7);

        if(n >= 6 || k == 9 || (n >= 3 && (k == 3 || k == 6))) ans.push_back(9);
        
        for(int i : ans) cout << i << " ";
        cout << "\n";

        


            
        
    }
}