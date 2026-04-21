#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(n == 1){
            cout << "1\n";
            continue;
        }


        for(int i = 1; i <= n; i++) cout << "2 ";
        cout << "\n";
    }
}