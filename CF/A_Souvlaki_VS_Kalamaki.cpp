#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main(){
    int tt; cin >> tt;


    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin(), a.end());


        bool flag = 1;

        for(int i = 2; i < n; i+=2) flag &= (a[i] == a[i+1]);

        cout << (flag ? "YES\n" : "NO\n");
    }
}