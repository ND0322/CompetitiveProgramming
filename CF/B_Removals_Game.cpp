#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        vector<int> a(n), b(n);

        for(int i = 0 ; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        if(a == b){
            cout << "Bob\n";
            continue;
        }

        reverse(a.begin(), a.end());
        if(a == b){
            cout << "Bob\n";
            continue;
        }

        cout << "Alice\n";






    }
}