#include <bits/stdc++.h>
#include <iostream>

#define int long long

using namespace std;


const int MAXN = 1e6+5;

int n, a[MAXN], b[MAXN];



int32_t main() {
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1,a+n+1);
    
    int l = 1;
    int r = n;
    int i = 1;

    while(l < r){
        b[i] = a[l++];
        i++;
        b[i] = a[r--];
        i++;
    }

    if(n&1) b[i] = a[l];

    for(int i = 1; i <= n-1; i++) cout << b[i] << " ";
    cout << b[n] << "\n";

    for(int i = 1; i <= n; i++){
        if(i == n){
            if(i&1){
                cout << "E\n";
                return 0;
            }
            cout << "S\n";
            return 0;
        }
        if(i&1) cout << "B";
        else cout << "S";
    }
}
