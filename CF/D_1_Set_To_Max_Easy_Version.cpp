#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(){
    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            cout << "NO\n";
            return;
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            bool flag = 0;
            for(int j = i-1; j >= 0; j--){
                if(a[j] == b[i]){
                    flag = 1;
                    break;
                }

                if(a[j] > b[i] || b[j] < b[i]){
                    break;
                }
            }

            for(int j = i+1; j < n; j++){
                if(a[j] == b[i]){
                    flag |= 1;
                    break;
                }
                if(a[j] > b[i] || b[j] < b[i]) break;
            }

            if(!flag){
                //cout << i << "\n";
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        solve();
    }
}