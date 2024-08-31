#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,q; cin >> n >> q;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int mx = a.back();

        while(q--){
            char c;
            int l,r;

            cin >> c >> l >> r;

            if(c == '+'){
                if(mx >= l && mx <= r) mx++;
            }
            else if(mx >= l && mx <= r) mx--;

            cout << mx << " ";
        }

        cout << "\n";

        


    }
}