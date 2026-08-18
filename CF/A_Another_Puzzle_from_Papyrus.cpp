#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
calculate once with and without rearrangement
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> a(n+1);

        vector<int> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];


        //don't use

        int opt1 = 0;
    
        for(int i = 1; i <= n; i++){
            if(a[i] < b[i]){
                opt1 = 2e9;
                break;
            }


            opt1 += a[i] - b[i];
        }


        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int opt2 = 0;

        for(int i = 1; i <= n; i++){
            if(a[i] < b[i]) opt2 = 2e9;
            opt2 += a[i] - b[i];
        }

        opt2 += k;

        int ans = min(opt1,opt2);

        cout << (ans >= 1e9 ? -1 : ans) << "\n";


    }
}