#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, tx, ty, psa[MAXN][2];

bool can(int x){
    for(int i = 1; i <= n-x; i++){
        int d = abs(tx - (psa[i+x][1] - psa[i-1][1])) + abs(ty - abs(psa[i+x][0] - psa[i-1][0]));
        if(d > x) continue;
        if(d&1 != n&1) continue;
        return 1;
    }
}

int main(){
    cin >> n;

    string s; cin >> s;

    cin >> tx >> ty;
    
    for(int i = 1; i <= n; i++){
        psa[i][0] = psa[i-1][0];
        psa[i][1] = psa[i-1][1];

        if(s[i-1] == 'U') psa[i][0]++;
        if(s[i-1] == 'D') psa[i][0]--;
        if(s[i-1] == 'L') psa[i][1]--;
        if(s[i-1] == 'R') psa[i][1]++;
    }
}