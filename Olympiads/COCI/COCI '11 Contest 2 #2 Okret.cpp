#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 15;

int n,m;

vector<int> di = {1,0,-1,0}, dj = {0, 1, 0, -1};

bool grid[MAXN][MAXN];


int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        for(int j = 0; j < m; j++) grid[i][j+1] = (s[j] == '.');
    }   

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!grid[i][j]) continue;
            int cnt = 0;
            for(int k = 0; k < 4; k++){

                if(grid[i + di[k]][j + dj[k]]) cnt++;
            }

            if(cnt <= 1){
                cout << "1\n";
                return 0;
            }
        }
    }

    cout << "0\n";

}