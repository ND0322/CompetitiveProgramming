#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n;
        double k; 
        cin >> n >> k;

        k /= 100;
        
        double ans = (pow(k, (n-1)/(double)n) - k) * 100;

        cout << setprecision(6) << fixed << "Case #" << _ << ": " << ans << "\n";
    }
}