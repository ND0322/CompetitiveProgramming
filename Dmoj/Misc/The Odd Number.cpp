#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int ans = 0;

    while(n--){
        int x; cin >> x;
        ans ^= x;
    }

    cout << ans << "\n";
    
}