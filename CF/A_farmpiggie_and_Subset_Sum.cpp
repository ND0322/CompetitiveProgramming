#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;


        vector<int> ans(n+1);
        for(int i = 1; i <= n; i+=2) ans[i] = i+1;
        for(int i = 2; i <= n; i+=2) ans[i] = i-1;

        for(int i = 1;i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}