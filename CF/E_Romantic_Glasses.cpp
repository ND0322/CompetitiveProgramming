#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        map<long long,int> m;
        long long pref = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(i&1) x = -x;
            pref += x;
            m[pref]++;
        }

        bool flag = 0;
        for(pair<long long, int> i : m){
            if(i.second > 1){
                flag = 1;
                break;
            }
        }

        cout << (m[0] || flag ? "YES\n" : "NO\n");




    }
}