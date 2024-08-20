#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;

#define int long long

const int MAXN = 1e6+5;


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, x; cin >> n >> x;

        multiset<int> s;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            s.insert(x);
        }

        int ans = 0;

        while(s.size()){
            int i = *s.begin();

            if(s.find(i * x) != s.end()){
                s.erase(s.begin());
                s.erase(s.find(i * x));
            }
            else{
                ans++;
                s.erase(s.begin());
            }
        }

        cout << ans << "\n";


    }
}