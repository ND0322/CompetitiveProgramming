#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, k, a[MAXN], psa[MAXN], suf[MAXN];

//easy just clear the prefix for each one if it aint the best

int32_t main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        pair<int,int> best = {-1,-1};
        memset(suf, 0, sizeof(suf));
        for(int i = 1; i <= n; i++){
            cin >> a[i];

            if(i == 1) a[i] += k;
            psa[i] = psa[i-1] + a[i];

            best = max(best, {a[i], -i});
        }

        for(int i = n; i >= 1; i--) suf[i] = max(a[i], suf[i+1]);


        for(int i = 1; i <= n; i++){
            if(i == -best.second){
                cout << "0 ";
                continue;
            }

            cout << (i-1 + (psa[i] < suf[i+1])) << " ";
        }

        cout << "\n";
    }
    
}
