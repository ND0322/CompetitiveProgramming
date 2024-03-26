#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n,m,k, dp[MAXN][15], st[15][MAXN<<1], l[MAXN], r[MAXN];

//dp[i][j]
//i cur pos with i being uncovered
//j num used

vector<int> enter[MAXN], leave[MAXN];

set s;


void build(int k){
    for(int i = n-1; i > 0; i--) st[k][i] = max(st[k][i<<1], st[k][i<<1|1]);
}



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m, k; cin >> n >> m >> k;

        for(int i = 0;  i< m ; i++){
            cin >> l[i] >> r[i];

            enter[l[i]].push_back(i);
            leave[r[i]].push_back(i);
        }

        for(int i = 1; i <= n; i++){
            
        }

        

        




    
        


    }
}