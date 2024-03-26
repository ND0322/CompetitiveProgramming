#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

map<int,int> l,r;

int main(){
    int tt; cin >> tt;
    while(tt--){
        l.clear();
        r.clear();

        int n; cin >> n;

        vector<int> a;

        long long cnt = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            a.push_back(x);
            
            
            r[x]++;
        }

        //sliding window
        for(int i = 0; i < n; i++){
            if(!l[a[i]]) cnt++;

            if(r[a[i]] == 1) ans += cnt;

            l[a[i]]++;
            r[a[i]]--;
        }

        cout << ans << "\n";

        



    }
}