#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        cout << n << "\n";
        
        for(int i = 0; i < n; i++){
            int targ = 1<<((int)ceil(log2(a[i])));

            cout << i+1 << " " << targ-a[i] << "\n";
        }
    }
}