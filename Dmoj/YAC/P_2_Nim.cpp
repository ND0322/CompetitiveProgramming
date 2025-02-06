#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);


        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];


            ans += (a[i] == 1);
        }
        
        if(ans & 1) cout << "Josh\n";
        else cout << "Mike\n";
    }
}