#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 18;
const int MOD = 998244353;


//if you find a dag that works reversing all edges creates a new dag
//ans would be edges * (#dag/2)
//the dags differ by their nodes

int n, m;

long long dp[1<<MAXN];

bool indep[1<<MAXN];

//dp = num dags using nodes in the mask
//indep is if a mask is an independant subset (no two nodes are connected)
//all submasks of independant submasks are independant as well
//for all independant subsets of mask:
//if(number of nodes in subset is odd) dp[mask] += dp[the rest of the mask]
//and because we overcount some
//if(number of nodes in subset is even) dp[mask] -= dp[the rest of the mask]



//every subset of an independant set is independant
//if it isnt then the whole thing isnt independant

/*
bool solve(int mask){
    if(__builtin_popcount(mask) == 2) return indep[mask];
    if(vis[MAXN]) return indep[mask];

    vis[mask] = true;

    for(int i = 0; i < n; i++)
        if(mask & (1<<i)) indep[mask] &= solve(mask^(1<<i));

    return indep[mask];


}s
*/


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    if(!m){
        cout << "0\n";
        return 0;
    }

    fill(indep, indep + (1<<n), 1);

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        indep[1<<(x-1) | 1<<(y-1)] = 0;
       
    }

    //same thing as the function
    for(int i = 0; i < n; i++){
        for(int j = (1<<n)-1; j >= 0; j--){
            if(j & (1<<i)) indep[j] &= indep[j ^ (1<<i)];
        }
    }

    dp[0] = 1;

    for(int i = 0; i < (1<<n); i++){
        //only looking for subsets no recusion needed
        for(int j = i; j >= 1; j = (j-1) & i ){
            if(indep[j]){
                if(__builtin_popcount(j) & 1) dp[i] = (dp[i] + dp[i^j]) % MOD;
                else dp[i] = (dp[i] - dp[i^j]) % MOD;
            }
        }
    }


  

    //https://math.stackexchange.com/questions/3361647/finding-inverse-of-2-mod-m
    int minv = ((1+MOD)/2);
    

    cout << ((dp[(1<<n)-1] + MOD) % MOD) * m % MOD * minv % MOD << "\n";

    

  


}