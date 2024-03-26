#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MOD = 998244353;

map<int,int> ex, ey;

int main(){
    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++) ex[a[i]] = b[i];

    int m; cin >> m;

    vector<int> c(m);
    vector<int> d(m);

    for(int i = 0; i < m; i++) cin >> c[i];
    for(int i = 0; i < m; i++) cin >> d[i];

    for(int i = 0; i < m; i++) ey[c[i]] = d[i];

    for(int i : c){
        if(ey[i] > ex[i]){
            cout << "0\n";
            return 0;
        }
    }

    int cnt = 0;

    for(int i : a){
        if(ex[i] > ey[i]) cnt++;
    }

    long long ans = 1;

    for(int i = 0; i < cnt; i++) ans = (ans*2)%MOD;
    cout << ans << "\n";
    



  
    
}

