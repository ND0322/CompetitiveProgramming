#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
need to end with n 1
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> ans(n+1);
        

        int cur = 1;
        for(int i = n; i >= 1; i-=2) ans[i] = cur++;

        cur = n;
        for(int i = n-1; i >= 1; i-=2) ans[i] = cur--;

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}

