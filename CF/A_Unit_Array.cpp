#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int sm = 0;

        int cnt = 0;
        

        int n; cin >> n;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            sm += x;
            cnt += (x == -1);
        }
        
        int tmp = cnt;
        cnt -= max(0, (int)ceil((0 - sm)/2.0));

        if(cnt & 1) cnt--;

        cout << tmp-cnt << "\n";
    }

    
}