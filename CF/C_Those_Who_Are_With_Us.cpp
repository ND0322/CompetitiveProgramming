#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//theyll belong to one row or column

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<vector<int>> a(n+1, vector<int>(m+1));

        int mx = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                mx = max(mx, a[i][j]);
            }
        }

        map<int,vector<int>> r, c;



        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == mx){
                    r[i].push_back(j);
                    c[j].push_back(i);
                }
            }
        }

        int x = -1,y = -1;


        for(auto i : c){
            if(i.second.size() > 1){
                y = i.first;
                break;
            }
        }

        for(auto i : r){
            if(i.second.size() > 1){
                x = i.first;
                break;
            }
        }


        if(x == -1){
             for(auto i : r){
                x = i.first;
                break;
            }
        }

        if(y == -1){
             for(auto i : c){

                bool flag = 0;
                for(int j : i.second){
                    if(j == x) flag = 1;
                }

                if(flag) continue;
                y = i.first;
                break;
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i == x || j == y) a[i][j]--;

                ans = max(ans, a[i][j]);

                if(i == x || j == y) a[i][j]++;
            }
        }

        x = -1,y = -1;


        for(auto i : c){
            if(i.second.size() > 1){
                y = i.first;
                break;
            }
        }

        for(auto i : r){
            if(i.second.size() > 1){
                x = i.first;
                break;
            }
        }

        if(y == -1){
             for(auto i : c){
                y = i.first;
                break;
            }
        }

        if(x == -1){
             for(auto i : r){

                bool flag = 0;
                for(int j : i.second){
                    if(j == y) flag = 1;
                }

                if(flag) continue;
                x = i.first;
                break;
            }
        }

        int ans2 = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i == x || j == y) a[i][j]--;

                ans2 = max(ans2, a[i][j]);

                if(i == x || j == y) a[i][j]++;
            }
        }

        cout << min(ans, ans2) << "\n";




    }
}