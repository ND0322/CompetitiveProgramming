#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 25;

bool grid[MAXN][MAXN];


int main() {
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int n; cin >> n;

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                char c; cin >> c;

                grid[i][j] = (c == '#');
                cnt += grid[i][j];
            }
        }

        if(sqrt(cnt) * sqrt(cnt) != cnt){
            cout << "Case #" << _ << ": NO\n";
            continue;
        }

        int m = sqrt(cnt);

        bool flag = 0;


        for(int i = 1; i+m-1 <= n; i++){
            for(int j = 1; j+m-1 <= n; j++){
                int cnt = 0;

                for(int a = i; a <= i+m-1; a++){
                    for(int b = j; b <= j+m-1; b++) cnt+=grid[i][j];
                }

                if(cnt == m*m) flag = 1;
            }
        }

        
        cout << "Case #" << _ << ": " << (flag ? "YES\n" : "NO\n");

    }
}