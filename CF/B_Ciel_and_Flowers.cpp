#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int a,b,c; cin >> a >> b >> c;

    int ans = 0;
    if(a > 0 && b > 0 && c > 0) ans = 1 + (a-1) / 3 + (b-1) / 3 + (c-1) / 3;
    if(a > 1 && b > 1 && c > 1) ans = max(ans, 2 + (a-2) / 3 + (b-2) / 3 + (c-2) / 3);

    ans = max(ans, a/3 + b/3 + c/3);

    cout << ans << "\n";
    
}