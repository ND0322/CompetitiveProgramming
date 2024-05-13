#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    int mx = 0;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mx = max(mx, x);
    }
    
    cout << mx << " ";
    mx = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mx = max(mx, x);
    }

    cout << mx << "\n";


}