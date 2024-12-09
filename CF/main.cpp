#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    int m; cin >> m;

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        if(abs(a[x] - a[y]) != 1) continue;

        swap(a[x], a[y]);

    }

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}