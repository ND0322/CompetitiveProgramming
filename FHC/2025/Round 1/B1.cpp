#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int a,b,n; cin >> n >> a >> b;

        
        cout << "Case #" << _ << ": ";

        for(int i = 1; i <= n; i++) cout << "1 ";
        cout << b << " ";
        for(int i = 1; i <= n-1; i++) cout << "1 ";
        cout << "\n";
    }
}