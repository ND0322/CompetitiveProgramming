#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        int pos = -1;
        for(int i = 1; i <= n ;i++){
            cin >> a[i];
            if(a[i] == n) pos = i;
        }

        swap(a[1], a[pos]);

        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";

        
    }
}