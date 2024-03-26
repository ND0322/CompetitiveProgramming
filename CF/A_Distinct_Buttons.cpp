#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        vector<bool> dir(4);

        int n; cin >> n;

        for(int i = 0; i < n; i++){
            int x,y; cin >> x >> y;

            if(x < 0) dir[3]=1;
            if(y<0) dir[2]=1;
            if(x>0) dir[0] = 1;
            if(y>0)dir[1] = 1;
        }

        if(dir[0] + dir[1] + dir[2] + dir[3] <= 3) cout << "YES\n";
        else cout << "NO\n";
    }
}