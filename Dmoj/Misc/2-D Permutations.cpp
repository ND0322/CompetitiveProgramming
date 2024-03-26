#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int n,m,q, psa[5000*5000+5];

int main(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            psa[i*j]++;
            psa[n*m - (n-i+1) * (m-j+1) + 2]--;
        }
    }

    for(int i = 1; i <= n*m; i++) psa[i] += psa[i-1];

    while(q--){
        int x; cin >> x;

        cout << psa[x] << "\n";
    }
}