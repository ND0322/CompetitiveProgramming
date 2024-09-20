#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        
        if(!(n&1)){
            cout << "YES\n";
            continue;
        }


        bool flag = 0;

        for(int i =0; i < n-1; i++){
            if(a[i] > a[i+1]) flag = 1;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}