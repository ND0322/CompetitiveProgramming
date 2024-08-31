#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5005;
const int MOD = 1e6+3;

int n, a[MAXN], dp[MAXN], st[MAXN<<2][2], near[MAXN], nearl[MAXN], last[MAXN];

pair<int,pair<int,int>> stl[MAXN<<2][2];

//lazy seg tree keeping track of dps we can access as we slide right to left
//r is easy to transition just consider the new i when sliding over
//if a[l] is included in the previous range we will get old transitions and maybe new ones
//otherwise we can only consider the stuff from near[l] onward 
//all between near[l] and near[near[l]] can be claimed 
//bsearch for the right we can have between near[l] and near[near[l]]
//segtree for min near left + cnt min + one example representative 
   

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        last[a[i]] = n;
    }

    for(int i = n; i >= 1; i--){
        near[i] = last[a[i]];
        last[a[i]] = i;
    }

    

    dp[n+1] = 1;
    for(int i = n; i >= 1; i--){  
    

        for(int j =0; j < 2; j++){

        }


        
    }

    cout << dp[1] << "\n";
}