#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <deque>

using namespace std;

int main(){
    int tt; cin >> tt;
    
    while(tt--){
        int n,m; cin >> n >> m;

    

        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cin >> a[i][j];
        }

        if(n == m && n == 1){
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < n; i++) rotate(a[i].begin(), a[i].end() - 1, a[i].end());

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++) cout << a[i][j] << " ";
            cout << "\n";
        }


        for(int j = 0; j < m; j++) cout << a[0][j] << " ";
        cout << "\n";

        
    }
}