#include <bits/stdc++.h>
#include <iostream> 
#include <iomanip>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mx = -1e9;

        long long sm = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            sm += x;
            mx = max(mx, x);
        }

        cout << setprecision(6) << fixed << mx + (sm-mx)/((long double)(n-1)) << "\n";
    }
}