#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//minimum ans is 2
//max is 3
//some cycle bs


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        bool flag = 0;

        for(int i = 1; i <= n; i++) flag |= (a[a[i]] == i);
        cout << 3-flag << "\n";
    }
}