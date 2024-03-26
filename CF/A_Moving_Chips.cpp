#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int l = -1;
        int r = -1;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];

            if(a[i] && l == -1) l = i;
            if(a[i]) r= i;
        }

        int cnt = 0;
        for(int i = l; i <= r; i++){
            cnt += !a[i];
        }

        cout<< cnt << "\n";
    }
}