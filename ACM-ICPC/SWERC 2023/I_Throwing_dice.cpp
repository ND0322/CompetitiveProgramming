#include <bits/stdc++.h>
#include <iostream>


using namespace std;

#define int long long

int32_t main(){
    //just compare expected values

    int n,m; cin >> n >> m;

    int a,b;
    
    a = n;
    b = m;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        a+=x;
    }

    for(int i = 0; i < m; i++){
        int x; cin >> x;
        b+=x;
    }

    if(a > b) cout << "ALICE\n";
    else if(b > a) cout << "BOB\n";
    else cout << "TIED\n";
}