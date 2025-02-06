#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> l(n+1), r(n+1);

        vector<int> psa(2*n+1);
        vector<int> cnt(2*n+1);

        for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
        

        for(int i = 1; i <= n; i++){
            if(l[i] == r[i]){
                psa[l[i]] = max(psa[l[i]], 1);
                cnt[l[i]]++;
            }
        }

        for(int i = 1; i <= 2*n; i++) psa[i] += psa[i-1];


        for(int i = 1; i <= n; i++){
            if(l[i] == r[i]){
                cout << (cnt[l[i]] == 1 ? "1" : "0");
                continue;
            }
            if(psa[r[i]] - psa[l[i]-1] == r[i] - l[i] + 1) cout << "0";
            else cout << "1";
        }

        cout << "\n";
    }
}