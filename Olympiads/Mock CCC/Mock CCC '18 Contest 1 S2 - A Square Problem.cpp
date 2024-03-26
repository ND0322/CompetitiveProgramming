#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 40;

int n, grid[MAXN][MAXN];

int main(){
    int n; cin >> n;



    for(int i = 0; i < n; i++){
        set<char> s;
        for(int j = 0; j < n; j++){

            char c; cin >> c;

            grid[i][j] = c;

            s.insert(c);
        }

        if(s.size() != n){
            cout << "No\n";
            return 0;
        }
    }

    int last = 0;
    int l = 0;

    for(int i = 0; i < n; i++){
        if(grid[0][i] < last){
            cout << "Latin\n";
            return 0;
        }

        if(grid[i][0] < l){
            cout << "Latin\n";
            return 0;
        }

        last = grid[0][i];
        l = grid[i][0];
    }

    cout << "Reduced\n";

}
