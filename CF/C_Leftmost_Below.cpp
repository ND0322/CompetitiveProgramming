#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int cnt = a[1];

        bool flag = 1;

        for(int i = 2; i <= n; i++){
            flag &= (a[i] <= 2 * cnt -1);
            cnt = min(cnt, a[i]);
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}