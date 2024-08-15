#include <bits/stdc++.h>
#include <iostream>
#include <set>


using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];    
        for(int i = 1; i <= n; i++) cin >> b[i];

        int m; cin >> m;

        vector<int> d(m+1);

        for(int i = 1; i <= m; i++) cin >> d[i];

        multiset<int> crapineed;
        set<int> s;

        for(int i = 1; i <= n; i++){
            if(a[i] != b[i]){
                crapineed.insert(b[i]);
            }
            s.insert(b[i]);
        }

        int hi1 = -1;
        int hi2 = -1;

        for(int i = 1; i <= m; i++){
            if(crapineed.find(d[i]) != crapineed.end()){
                crapineed.erase(crapineed.find(d[i]));
            }
            if(s.find(d[i]) == s.end()) hi2 = i;
            else hi1 = i;
        }

        if(crapineed.size()){
            cout << "NO\n";
            continue;
        }

        cout << (hi2 < hi1 ? "YES\n" : "NO\n");


        
    }
}