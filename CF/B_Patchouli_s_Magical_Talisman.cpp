#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mn = 1e9;
        long long sm = 0;
        bool flag = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            if(x&1) flag = 1;
            else{
                mn = min(mn, x);
                sm += x;
                cnt++;
            }
        }

        if(cnt == 0){
            cout << "0\n";
            continue;
        }

        if(flag){
            cout << cnt << "\n";
            continue;
        }

        cout << min(cnt-1 + log2(mn), log2(sm)) << "\n";

        


    }
}