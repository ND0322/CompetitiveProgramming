#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    //runs
    //delete 

    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            a[i] = c - '0';
        }

        //count bad ones and zeros

        int c[2] = {0,0};

        for(int i = 2; i <= n; i++){
            if(a[i-1] == a[i]) c[a[i]]++;
        }

        int mn = min(c[0], c[1]);

        c[0] -= mn;
        c[1] -= mn;

        int ans = 2 * mn;

        if(!c[0] && !c[1]){
            cout << ans << "\n";
            continue;
        }
        if(c[0]){
            c[0]--;
            ans++;

            if(!c[0]){
                cout << ans << "\n";
                continue;
            }

            if(c[0] > a[1] + a[n]){
                cout << "-1\n";
                continue;
            }

            ans += 2 * c[0];
            cout << ans << "\n";
            continue;
        }

        c[1]--;
        ans++;
        if(!c[1]){
            cout << ans << "\n";
            continue;
        }

        if(c[1] > 2 - a[1] - a[n]){
            cout << "-1\n";
            continue;
        }

        ans += 2 * c[1];
        cout << ans << "\n";


        


        
    }
}