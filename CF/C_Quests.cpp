#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

const int MAXN = 2e5+5;

int n,k;

long long a[MAXN], b[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
       
        cin >> n >> k;

        for(int i = 0; i< n; i++) cin >> a[i];
        for(int j = 0; j < n; j++) cin >> b[j];

        long long pref = 0;
        long long pmax = 0;
        long long ans = 0;

        for(int i = 0; i < min(n,k); i++){
            pref += a[i];
            pmax = max(pmax, b[i]);
            //cout << pref << "\n";
            ans = max(ans, pref + (k-i-1) * pmax);
        }

        cout << ans << "\n";

       

    }
}