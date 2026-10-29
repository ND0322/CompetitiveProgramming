#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            a[x]++;
        }

        bool flag = 1;
        for(int i = 0; i <= n; i++){
            if(a[i] >= 2 * k) continue;
            if(a[i] == 2*k-1) break;
            if(a[i] < 2 * k -1){
                flag = 0;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}