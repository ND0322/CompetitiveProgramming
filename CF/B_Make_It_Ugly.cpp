#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        bool flag = 1;

        for(int i = 1; i <= n; i++) flag &= (a[i] == a[1]);

        if(flag){
            cout << "-1\n";
            continue;
        }

        int l = 1e9;
        int cnt = 0;

        for(int i = 1; i <= n; i++){
            if(a[1] == a[i]) cnt++;
            else{
                l = min(l,cnt);
                cnt = 0;
            }
        }

        cout << min(l,cnt) << "\n";
    }
}