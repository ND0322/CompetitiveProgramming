#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//two things create a cycle

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        vector<int> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        int cnt = 0;
        int sm = 0;

        for(int i = 1; i <= n; i++){
            cnt += b[i] > a[i];

            sm += max(0, b[i] - a[i]);
        }

        if(cnt > 1){
            cout << "NO\n";
            continue;
        }


        cnt = 0;

        for(int i = 1; i <= n; i++){
            a[i] -= b[i];
            if(a[i] < sm) cnt++;
        }

        cout << (cnt > 1 ? "NO\n" : "YES\n");
    }
}