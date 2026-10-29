#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    //there is a solution using only powers of 2


    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;


        int k = log2(n);

        vector<int> ans;

        int l = (1<<k+1);

        for(int i = 1; i < l<<1; i++){
            int a = (i-1) % l;
            int b = i % l;

            ans.push_back((a ^ (a>>1)) ^ (b ^ (b>>1)));
        }

        cout << ans.size() << "\n";

        for(int i : ans) cout << i << " ";
        cout << "\n";
        
    }
}