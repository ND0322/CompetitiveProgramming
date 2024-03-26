#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>


using namespace std;

const int MAXN = 105;
int grid[MAXN][MAXN];

vector<pair<pair<int,int>, int>> ans;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        ans.clear();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) cin >> grid[i][j];
        }

        queue<int> r, c;

        for(int i = 1; i <= n; i++){
            set<int> s;

            for(int j = 1; j <= n; j++) s.insert(grid[i][j]);
            if((int)s.size() == n) r.push(i);
        }

        for(int i = 1; i <= n; i++){
            set<int> s;
            for(int j = 1; j <= n; j++) s.insert(grid[j][i]);
            if((int)s.size() == n) c.push(i);
            
        }

        while(r.size() && c.size()){
            int x = r.front();
            int y = c.front();

            r.pop();
            c.pop();

            ans.push_back({{x,y}, (grid[x][y] == 1 ? 2 : 1)});
            grid[x][y] = (grid[x][y] == 1 ? 2 : 1);
        }

       

        while(r.size()){
            int x = r.front();

            r.pop();

            int targ = -1;

            //x,1

            set<int> s;

            for(int i = 1; i <= n; i++){
                if(i == x) continue;
                s.insert(grid[i][1]);
            }

            if((int)s.size() == 1 && *s.begin() == grid[x][1]) ans.push_back({{x,1}, (grid[x][1] == 1 ? 2 : 1)});
            else ans.push_back({{x,1}, (*s.begin() == grid[x][1] ? *s.rbegin() : *s.begin())});


            
        }


        while(c.size()){
            int x = c.front();


            c.pop();

            //1,x

            set<int> s;

            for(int i = 1; i <= n; i++){
                if(i == x) continue;
                s.insert(grid[1][i]);
            }

            if((int)s.size() == 1 && *s.begin() == grid[1][x]) ans.push_back({{1,x}, (grid[1][x] == 1 ? 2 : 1)});
            else ans.push_back({{1,x}, (*s.begin() == grid[1][x] ? *s.rbegin() : *s.begin())});

            
        }



        cout << (int)ans.size() << "\n";

        for(auto c : ans) cout << c.first.first << " " << c.first.second << " " << c.second << "\n";




    }


}