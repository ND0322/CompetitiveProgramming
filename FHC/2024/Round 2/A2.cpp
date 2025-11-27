#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//pos, last, less, more 
//800 states * 9 transitions * 18 lengths
int a,b, m, dp[20][10][2][2];
/*
digit dp
*/

//use ulimit -s unlimited

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> a >> b >> m;

        for(int l = log10(a); l <= log10(b); l++){
            if(!(l&1)) continue;

            for(int i = 0; i <= 9; i++) dp[l+1][i][1][1] = 
        }

        cout << "Case #" << _ << ": " << ans << "\n";
    }
}


