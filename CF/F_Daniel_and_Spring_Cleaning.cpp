#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 65;

int dp[MAXN][2][2][2][2];

int l,r; 

/*
number such that a & b = 0
digit dp simple

a lb, a ub, b lb, b ub, cur bit

either place 1 or 0
             0    1
*/


int msb(int x){
    return 31 - __builtin_clz(x);
}


int solve(int i, bool al, bool au, bool bl, bool bu){
    if(i == -1) return 1;

    

    if(dp[i][al][au][bl][bu] != -1) return dp[i][al][au][bl][bu];

    dp[i][al][au][bl][bu] = 0;
   
    //place 1 0
    //means a upper bound has have been lowered or this is a 1 
    //means b lower bound has to have been raised or this is a 0
    if((au || (r & (1<<i))) && (bl || !(l & 1<<i))){
        bool nal = al | !(l & (1<<i));
        bool nbu = bu |(r & (1<<i));

        

        dp[i][al][au][bl][bu] = solve(i-1, nal, au, bl, nbu);
    }

    if((al || !(l & 1<<i)) && (bu || (r & (1<<i)))){
        bool nbl = bl | !(l & (1<<i));
        bool nau = au |(r & (1<<i));


        dp[i][al][au][bl][bu] += solve(i-1, al, nau, nbl, bu);
    }

    //0 0

    if((bl || !(l & 1<<i)) && (al || !(l & 1<<i))){
        bool nau = au |(r & (1<<i));
        bool nbu = bu |(r & (1<<i));

        dp[i][al][au][bl][bu] += solve(i-1, al, nau, bl, nbu);
    }


    return dp[i][al][au][bl][bu];
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> l >> r;

        memset(dp, -1, sizeof(dp));

        if(r == 0){
            cout << "1\n";
            continue;
        }


        cout << solve(msb(r), 0,0,0,0) << "\n";

        
    }
}