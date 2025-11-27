#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin(), a.end());


        int cnta = 0;
        int mxa = 0;
        int cntb = 0;
        int mnb = 1e9;
        for(int i = 1; i <= n; i++){
            if(a[i] < k){
                cnta++;
                mxa = max(mxa, a[i]);
            }
            else if(a[i] > k){
                cntb++;
                mnb = min(mnb, a[i]);
            }
        }

        if(cnta > cntb) cout << mxa << "\n";
        else cout << mnb << "\n";

        
    }
}