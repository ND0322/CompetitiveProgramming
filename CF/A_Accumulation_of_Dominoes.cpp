#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    long long n, m; cin >> n >> m;

    if(m == 1){
        cout << n-1 << "\n";
        return 0;
    }

    cout << (m-1) * n << "\n";
}