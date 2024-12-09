#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool query(int i, int j){
    cout <<"? " << i << " " << j << "\n";
    bool x; cin >> x;
    return x;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int ans = -1;

        for(int i = 1; i < n; i += 2){
            if(query(i, i+1) != query(i+1, i)){
                ans = i;
                break;
            }
        }

        if(ans == -1){
            cout << "! " << n << "\n";
            continue;
        }

        cout << "! ";

        if(ans == 1){
            if(query(ans+1, ans+2) != query(ans+2, ans+1)) cout << ans+1 << "\n";
            else cout << ans << "\n";
        }
        else{
            if(query(ans, ans-1) != query(ans-1, ans)) cout << ans << "\n";
            else cout << ans+1 << "\n";
        }
    }
}