#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//simple greedy the first guy gets contributed a 

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m,k; cin >> n >> m >> k;

        for(int i = n; i > m; i--) cout << i << " ";
        for(int i = 1; i <= m; i++) cout << i << " ";
        cout << "\n";
    }
}