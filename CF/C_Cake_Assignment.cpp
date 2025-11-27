#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){

        long long k,x; cin >> k >> x;

        long long y = (1LL << (k+1)) - x;


        long long targ =  1LL<<k;
        vector<int> ans;
        while(x != targ){
            if(x < y){
                ans.push_back(1);
                y-=x;
                x*=2;
            }
            else{
                ans.push_back(2);
                x-=y;
                y*=2;
            }
        }

        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());

        for(int i : ans) cout << i << " ";

        cout << "\n";




    }
}