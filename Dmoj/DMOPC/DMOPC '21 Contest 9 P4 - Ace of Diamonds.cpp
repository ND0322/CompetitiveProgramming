#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e6+5;

int n,m;

//just do the same sh just compress the row into one thing
//flipping is the same as solving the row

vector<vector<bool>> grid, done;

void solve(int r){
    set<int> s;
    for(int i = 1; i <= m; i++){
        if(grid[r][i]) s.insert(i);
    }

    //cout << r << " " << s.size() << "\n";



    while(!s.empty()){
        int x = *s.begin();

        cout << r << " " << x << "\n";

        if(x > 1){
            grid[r][x-1] = !grid[r][x-1];

            if(!grid[r][x-1] && s.find(x-1) != s.end()) s.erase(x-1);
            if(grid[r][x-1] && !done[r][x-1]) s.insert(x-1);   
        }
        if(x < m){
            grid[r][x+1] = !grid[r][x+1];

            if(!grid[r][x+1] && s.find(x+1) != s.end()) s.erase(x+1);
            if(grid[r][x+1] && !done[r][x+1]) s.insert(x+1);   
        }

        if(r > 1) grid[r-1][x] = !grid[r-1][x];
        if(r < n) grid[r+1][x] = !grid[r+1][x];

        done[r][x] = 1;
        s.erase(x);
    }


}

int main(){
    cin >> n >> m;
   
    grid = vector<vector<bool>> (n+1, vector<bool>(m+1, 0));
    done = vector<vector<bool>> (n+1, vector<bool>(m+1, 0));
    vector<bool> a(n+1);
    vector<bool> mic(n+1);

    int cnt = 0;

    set<int> s;

    for(int i = 1; i <= n; i++){
        int cur = 0;
        for(int j = 1; j <= m; j++){
            char c; cin >> c;

            grid[i][j] = (c == 'H');
            cur += grid[i][j];
        }

        a[i] = (cur & 1);
        if(a[i]) s.insert(i);
        cnt += cur;
    }

   

    if(!(cnt & 1)){
        cout << "-1\n";
        return 0;
    }

   

    while(!s.empty()){
        int x = *s.begin();

        solve(x);

        if(x > 1){
            a[x-1] = !a[x-1];

            if(!a[x-1] && s.find(x-1) != s.end()) s.erase(x-1);
            if(a[x-1] && !mic[x-1]) s.insert(x-1);   
        }
        if(x < n){
            a[x+1] = !a[x+1];

            if(!a[x+1] && s.find(x+1) != s.end()) s.erase(x+1);
            if(a[x+1] && !mic[x+1]) s.insert(x+1);   
        }

        
        mic[x] = 1;
        s.erase(x);
    }



    

    

}