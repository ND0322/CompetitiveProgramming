#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<bool> had(n+2);

        int ans = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(had[x+1]) ans++;
            had[x] = 1;
        }

        cout << ans << "\n";

    }
}