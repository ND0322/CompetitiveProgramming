#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        //check to perform the entire array mex and then 0 it

        vector<int>a(n+2);
        long long flag = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            flag += a[i];
        }

        if(!flag){
            cout << "0\n";
            continue;
        }

        int ans = 0;
        for(int i = 0; i <= n; i++) ans += (!a[i] && a[i+1] != 0);
        cout << min(ans,2) << "\n";
    }
}