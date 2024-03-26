#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//greedy
//go bit by bit either do or do not

const int MAXN = 35;

int cnt[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < n; i++){
            int x; cin >> x;

            for(int j = 0; j < k; j++) cnt[j] += (bool)(x & (1<<j));
        }

        int ans = 0;
        for(int j = 0; j < k; j++){
            //cout << j << " " << cnt[j] << "\n";
            if(cnt[j] > n/2) ans += (1<<j);
        }

        cout << ans << "\n";


    }
}