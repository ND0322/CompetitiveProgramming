#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mx[2] = {0,0};
        int cnt[2] = {0,0};

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            cnt[i&1]++;
            mx[i&1] = max(mx[i&1], x); 
        }

        cout << max(mx[0] + cnt[0], mx[1] + cnt[1]) << "\n";
    }
}