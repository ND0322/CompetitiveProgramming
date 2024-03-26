#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >>n;

        long long sum = 0;
        long long mx = 0;

        for(int i = 0; i < n; i ++){
            int x; cin >> x;

            sum += x;
        }

        for(int i = 0; i < n; i++){
            long long x; cin >> x;

            sum += x;
            mx = max(mx,x);
        }

        cout << sum-mx << "\n";
    }
}