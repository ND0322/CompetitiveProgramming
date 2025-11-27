#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    long long a,b,c,d; cin >> a >> b >> c >> d;

    cout << min(a + c + max(b,d), b + d + max(c,a)) * 2 << "\n";
}