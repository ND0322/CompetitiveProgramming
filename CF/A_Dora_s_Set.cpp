#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int l,r; cin >> l >> r;

        int cnt[2] = {0,0};
        

        for(int i = l; i <= r;i ++) cnt[i&1]++;

        cout << min(cnt[0], cnt[1]/2) << "\n";
        
    }
}