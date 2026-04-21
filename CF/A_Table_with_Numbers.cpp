#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, h, l; cin >> n >> h >> l;
       
        map<int,int> mp;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            mp[x]++;
        }

        int ans = 0;

        for(auto [i,j] : mp){
            
        }
    }
}