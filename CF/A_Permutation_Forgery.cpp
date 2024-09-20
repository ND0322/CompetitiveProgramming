#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0;  i < n; i++) cin >> a[i];

        reverse(a.begin(), a.end());

        for(int i : a) cout << i << " ";
        cout << "\n";
    }
}