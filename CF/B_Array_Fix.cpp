#include <bits/stdc++.h>
#include <iostream>


using namespace std;


void solve(){
    int n; cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = n-2; i >= 0; i--){
        if(a[i] > a[i+1]){
            if(a[i]%10 <= a[i+1] && a[i]/10 <= a[i]%10) a[i] /= 10;
            else{
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}
int main(){
    int tt; cin >> tt;

    while(tt--) solve();
}