#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    //if all 1s we have special case 

    int tt; cin >> tt;

    for(int _ = 0; _ < tt; _++){
        int x,y; cin >> x >> y;

        vector<int> ans(x+y+1);

        for(int i = 1; i <= x; i++) ans[i] = 1;
        for(int i = x+1; i <= x+y; i++) ans[i] = -1;

        if(x < y) swap(x,y);

        if(x == y) cout << "1\n";
        else{

            int ans = 0;

            for(int i = 1; i * i <= x-y; i++){
                if((x-y) % i) continue;

                if(i * i == x - y) ans++;
                else ans += 2;
            }

            cout << ans << "\n";
        }
        
        for(int i = 1; i <= x+y; i++) cout << ans[i] << " ";
        cout << "\n";

    }
}