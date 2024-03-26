#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    long long n; cin >> n;

    while(!(n&1)) n>>=1;
    while(!(n%3)) n/=3;

    if(n > 2) cout << "No\n";
    else cout << "Yes\n";
}