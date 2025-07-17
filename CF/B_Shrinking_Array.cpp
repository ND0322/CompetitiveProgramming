#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//only 0, -1, 1


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1); 

        for(int i = 1; i <= n; i++) cin >> a[i];

        bool flag = 0;

        for(int i = 1; i < n; i++) flag |= (abs(a[i] - a[i+1]) <= 1);

        if(flag){
            cout << "0\n";
            continue;
        }

        for(int i = 1; i < n-1; i++) flag |= (a[i] >= min(a[i+1], a[i+2]) - 1 && a[i] <= max(a[i+1], a[i+2]) + 1);
        for(int i = 3; i <= n; i++) flag |= (a[i] >= min(a[i-1], a[i-2]) - 1 && a[i] <= max(a[i-1], a[i-2]) + 1);
        if(flag) cout << "1\n";
        else cout << "-1\n";
    }
}