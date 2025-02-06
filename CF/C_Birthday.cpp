#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for(int i = 1; i <= n; i+=2) cout << a[i] << " ";

    for(int i = n - (n&1); i >= 1; i-=2) cout << a[i] << " ";

    cout << "\n";
}