#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
k adjacent pairs means how many changes

with wiggle room at only the endpoints 
n - k -1 changes
*/

int main(){
    //make first two things equal and alternate

    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        int changes = n-k-1;

        if(!changes){
            cout << "-1\n";
            continue;
        }

        vector<int> ans;

        ans.push_back(0);

        int ind = 0;
        for(int i = 1; i <= n; i++){
            if(changes == 0) break;

            ans.push_back(i & 1);
            ind = i;
            changes--;
        }

        for(int i = 1; i <= (n - ind) / 2; i++) ans.push_back(ind & 1);
        while(ans.size() < n+1) ans.push_back(!(ind & 1));

        int cnt = 0;

        for(int i = 1; i <= n; i++) cnt += ans[i];

        if(abs(cnt - n + cnt) > 1) cout << "-1\n";
        else for(int i = 1; i <= n; i++) cout << ans[i];
        cout << "\n";


    }
}