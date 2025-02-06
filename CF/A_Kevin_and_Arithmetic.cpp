#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int a = 0;
        int b = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            if(x&1) a++;
            else b++;
        }

        if(!b && a >= 2){
            a -= 2;
            b++;
        }

        int ans = min(a+1,b);

        if(ans) ans += max(0, a+1-b);

        cout << ans << "\n";





        
    }
}