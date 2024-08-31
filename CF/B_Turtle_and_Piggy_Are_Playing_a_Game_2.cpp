#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int>a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        if((n&1)) cout << a[(n+1)/2] << "\n";
        else cout << a[(n+1)/2+1] << "\n";
    }
}