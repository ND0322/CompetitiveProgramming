#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n+1);
    vector<int> b(n+1);

    long long sm = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sm += a[i];
    
    }

    for(int i = 0; i < n; i++) cin >> b[i];

    sort(b.rbegin(), b.rend());

    cout << (sm <= b[0] + b[1] ? "YES\n" : "NO\n");


}