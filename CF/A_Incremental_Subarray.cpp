#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
if there is 1 followed by non 1 then answer is 1

otherwise its n - max+1
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<int> a(m+1);
        int mx = 0;
        for(int i = 1; i <= m; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        bool flag = 0;
        for(int i = 1; i < m; i++) flag |= (a[i] != 1 && a[i+1] == 1);
        flag |= (a[1] == 1 && a[2] == 1);

        if(flag){
            cout << "1\n";
            continue;
        }


        cout << n - mx + 1 << "\n";

        

        


    }
}