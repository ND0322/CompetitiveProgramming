#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n,m; cin >> n >> m;

    if(!m){
        cout << "1\n";
        return 0;
    }

    if(m <= n/2){
        cout << m << "\n";
        return 0;
    }

    m -= n/2;
    if(n&1) m--;

    cout << n/2 - m << "\n";
}