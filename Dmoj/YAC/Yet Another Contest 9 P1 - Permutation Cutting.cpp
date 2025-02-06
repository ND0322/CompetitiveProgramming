#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n+2);
    vector<int> b(n+2);
    vector<int> pos(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> b[i];

        pos[b[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        if(a[i+1] == b[pos[a[i]]+1]) ans++;
        if(a[i-1] == b[pos[a[i]]-1]) ans++;
    }

    cout << max(1,n-ans/2) << "\n";

}