#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, q;

bool grid[MAXN][MAXN];

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        for(int j = 0; j < n; j++) grid[i][j+1] = s[j] == '1';
    }

    while(q--){
        int a,b,x,y; cin >> a >> b >> x >> y;

        cout << abs(a-x) + abs(b-y) << "\n";
    }
}