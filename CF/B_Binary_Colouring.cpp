#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int ans[35];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x; cin >> x;

        memset(ans,0,sizeof(ans));

        int msb = 0;
        for(int i = 0; i < 30; i++){
            ans[i] = (bool)(x & (1<<i));
            if(x & (1<<i)) msb = i;
        }

       

        for(int i = 0; i <= msb; i++){
            if(ans[i] && ans[i+1]){
                ans[i] = -1;
                ans[i+1] = 0;
                int nxt = i+2;
                while(ans[nxt]) ans[nxt++] = 0;
                
                ans[nxt] = 1; 
            }
        }

        cout << "32\n";
        for(int i = 0; i < 32; i++) cout << ans[i] << " ";
        cout << "\n";




    }
}

