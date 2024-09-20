#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<int> mn,mx;

        for(int i = 0; i < n; i++){
            mn.push_back(min(a[i], b[i]));
            mx.push_back(max(a[i], b[i]));
        }

        bool flag = 1;

        for(int i = 0; i < n; i++){
            flag &= (mn[i] <= mn[n-1]);
            flag &= (mx[i] <= mx[n-1]);
        }

        cout << (flag ? "YES\n" : "NO\n");


    }
}