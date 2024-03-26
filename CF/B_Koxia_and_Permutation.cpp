#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;


        //alternating works for all cases

        vector<int> ans(n+1);

        int cnt = n;
        for(int i = 1; i <= n; i+=2) ans[i] = cnt--;
        cnt = 1;
        for(int i = 2; i <= n; i+=2) ans[i] = cnt++;
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    


    }
}