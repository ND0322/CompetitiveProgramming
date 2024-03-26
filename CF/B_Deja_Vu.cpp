#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, q; cin >> n >> q;

        vector<int>a(n);
        vector<int>b;

        for(int i = 0; i < n; i++) cin >> a[i];
        
        int small = 1e9;

        for(int i = 0; i < q; i++){
            int x; cin >> x;

            if(x < small){
                small = x;
                b.push_back(x);
            }
        }

        for (int i: b) {
            for (int j = 0; j < n; j++) {
            if (!(a[j]%(1<<i))) a[j] += (1<<(i-1));
            
            }
        }
        for (int i: a) cout << i << ' ';
        cout << '\n';
    }
}