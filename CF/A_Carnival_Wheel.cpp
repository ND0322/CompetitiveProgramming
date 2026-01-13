#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int l,a,b; cin >> l >> a >> b;

        set<int> s;

        int ans = 0;
        while(1){
            a = (a + b) % l;

            if(s.find(a) != s.end()) break;
            ans = max(ans, a);
            s.insert(a);
        }

        cout << ans << "\n";
    }
}