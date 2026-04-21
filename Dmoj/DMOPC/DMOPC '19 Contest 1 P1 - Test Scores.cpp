#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long n,a,b,c; cin >> n >> a >> b >> c;

        //x * a - (n-x) * b >= c
        //ax - bn + bx >= c
        //ax + bx >= c + bn
        //x >= c + bn / (a+b)

        if(n * a < c) cout << "-1\n";
        else cout << ceil((c + b * n) / (long double)(a+b)) << "\n";
    }
}