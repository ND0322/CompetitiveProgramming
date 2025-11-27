#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
op 1 and 2 never intersect

fill everything with k 
how to deal with 2s 


if a larger range covers a smaller range delete the big one 
do i mod k
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k, q; cin >> n >> k >> q;

        vector<int> ans(n+1, 0);

        while(q--){
            int c,l,r; cin >> c >> l >> r;

            if(c == 1){
                for(int i = l; i <= r; i++) ans[i] = k;
                continue;
            }

            for(int i = l; i <= r; i++){
                if(!ans[i]) ans[i] = i % k;
            }
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
}