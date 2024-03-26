#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n);

        for(int i = 0; i < n;i ++){
            cin >> a[i];
        }

        if(n == 1){
            cout << "0\n";
            continue;
        }

        sort(a.begin(),a.end());

        vector<int> bad;

        for(int i = 0; i < n-1; i++ ){
            if(a[i+1] - a[i] > k){
                bad.push_back(i);
            }
        }

        int ans = 1e9;

        cout << "good\n";

        
         for(int i = 0; i < bad.size()-1; i++){
            cout << bad[i] << endl;
        }
        

       

        cout << ans << "\n";

        
    }
}