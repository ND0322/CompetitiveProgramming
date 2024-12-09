#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+5);
        vector<long long> psa(n+5);

        for(int i = 1; i <= n; i++){
            cin >> a[i];

            psa[i] = psa[i-1] + a[i];
        }


        cout << a[n] + psa[n-2] - a[n-1] << "\n";
        
    }
}