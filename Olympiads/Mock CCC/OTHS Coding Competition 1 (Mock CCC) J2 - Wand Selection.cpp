#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;
    sort(a.begin(),a.end());

    for(int i = 0; i < n-1; i++) sum += a[i];

    cout << sum/(n-1) << "\n";
}