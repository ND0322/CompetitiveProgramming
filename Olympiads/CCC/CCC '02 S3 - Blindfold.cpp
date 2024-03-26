#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 3e4+5;

int n, r, c, t[MAXN];

vector<pii> offset[4];

//bool visited[400][85][4][MAXN];

char grid[400][85];

vector<int> di = {-1,0,1,0}, dj = {0,1,0,-1};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> r >> c;

    for(int i = 0; i < r; i++){
        string s; cin >> s;

        for(int j = 0; j < c; j++){
            grid[i][j] = s[j];
            
        }
    }

    cin >> n;

    


    for(int i = 0; i < n; i++){
        char s; cin >> s;

        if(s == 'F') t[i] = 0;
        if(s == 'L') t[i] = -1;
        if(s == 'R') t[i] = 1;
    }

    for(int i = 0; i < 4; i++){
        int x = 0;
        int y = 0;
        int dir = i;

      

        for(int j = 0; j < n; j++){
            if(!t[j]){
                x += di[dir];
                y += dj[dir];
            }
            else{
                dir = (dir+4+t[j]) % 4;
            }

            offset[i].push_back({x,y});


        }
    }
    /*
    for(int i = 0; i < 4; i++){
        
        sort(offset[i].begin(), offset[i].end());
        offset[i].erase(unique(offset[i].begin(), offset[i].end() ), offset[i].end());
        
    
    }
    */
    

    //0 is up
    //1 is right
    //2 is down
    //3 is left

   

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){

            if(grid[i][j] == 'X') continue;
            for(int k = 0; k < 4; k++){

                bool check = 1;
                for(pii o : offset[k]){
                    if(i + o.first < 0 || i+o.first >= r || j + o.second < 0 || j + o.second >= c){
                        check = 0;
                        break;
                    }

                    if(grid[i+o.first][j+o.second] == 'X'){
                        check = 0;
                        break;
                    }
                }

                if(check){
                    //cout << i << " " << offset[k][n-1].first << " " << j << " " << offset[k][n-1].second << " " << k << "\n";
                    grid[i+offset[k][n-1].first][j+offset[k][n-1].second] = '*';
                }
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << grid[i][j];
        }

        cout << "\n";
    }
    
    return 0;

    



    

    

    /*
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 'X') break;
            for(int l = 0; l < 4; l++){
                int x = i;
                int y = j;
                bool check = 1;
                int dir = l;

                

                for(int k = 0; k < n; k++){
                    
                    if(t[k] == 0){
                        x += di[dir];
                        y += dj[dir];
                    }

                    else{
                        dir = (dir+4+t[k]) % 4;
                    }

                    //if(visited[x][y][dir][k]){
                        //check = 0;
                        //break;
                    //}

                    //visited[x][y][dir][k] = 1;

                    //if(i == 0 && j == 0 && l == 1) cout << x << " " << y << " " << dir << " " << grid[x][y] << "\n";
                    

                    if(x < 0 || x >= r || y < 0 || y >= c){
                        //cout << x << " " << y << " " << dir << " " << k << "\n";
                        check = 0;
                        break;
                    }

                    if(grid[x][y] == 'X'){
                        //cout << x << " " << y << " " << dir << " " << k << "\n";
                        check = 0;
                        break;
                    }

                }

                

                if(check){
                    
                    grid[x][y] = '*';
                } 
                




            }
        }
    }

    */

    

    
    
}