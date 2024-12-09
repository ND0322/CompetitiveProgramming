#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

//check first occurence of each person
//check for subsequence 

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m, q; cin >> n >> m >> q;

        vector<int> a(n+2);
        vector<int> b = {-1};

        set<int> has; 


        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 0; i < m; i++){
            int x; cin >> x;

            if(has.find(x) != has.end()) continue;
            has.insert(x);
            b.push_back(x);
        }


        bool ans = 1;
        for(int i = 1; i < b.size(); i++){
            if(a[i] != b[i]) ans = 0;
        }

        cout << (ans ? "YA\n" : "TIDAK\n");

        
    }
}