#include <bits/stdc++.h> 
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<set<int>> mx(n+1, set<int>());

        set<int> valid;

        vector<int> ans;

        vector<vector<int>> a(n+1, vector<int>());

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            for(int j = 0; j < x; j++){
                int y; cin >> y;

                a[i].push_back(y);
            }
        }

        
    }
}