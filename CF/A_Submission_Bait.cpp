#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int mx = 0;


        map<int,int> mp;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            mp[x]++;
        }

        bool flag = 0;

        for(auto i : mp){
            if(i.second & 1){
                flag = 1;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}