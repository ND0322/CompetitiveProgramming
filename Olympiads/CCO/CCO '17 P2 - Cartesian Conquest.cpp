#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

//rotate the grid so the width is always more than the height
//we can cut (l,l/2), (l,l*2), (w/2, w)
//this is too slow for full

long long hsh(int a,int b){
    if(a < b) swap(a,b);
    return a * 1e8 + b;
}



int n, m;

unordered_map<long long,pair<int,int>> dp;

inline void solve(int x, int y){
    if(x < y) swap(x,y);
    if(!x || !y){
        dp[hsh(x,y)] = {0,0};
        return;
    }

    if(dp.count(hsh(x,y))) return;

    int &mn = dp[hsh(x,y)].first;
    int &mx = dp[hsh(x,y)].second;

    mn = 1e9;
    mx = -1e9;

    if(x > (y<<1)){
        int tmp = x%(y<<1);

        solve(tmp,y);
        mn = dp[hsh(tmp,y)].first + x/(y<<1);
        mx = dp[hsh(tmp,y)].second + x/(y<<1);

        if(!(y&1)){
            int a = ceil(tmp/(double)(y>>1));
            int b = (x/(y<<1))-1;
            int tmmp = (y<<1) + tmp - a*(y>>1);
            solve(tmmp, y);
            mn = min(mn,dp[hsh(tmmp,y)].first + a + b);
            mx = max(mx,dp[hsh(tmmp,y)].second + a + (b<<2));
        }
        return;
    }

    if(y >= (x>>1) && !(x&1)){
        solve(x,y-(x>>1));
        mn = min(mn, dp[hsh(x,y-(x>>1))].first);
        mx = max(mx, dp[hsh(x,y-(x>>1))].second);
    }
    if(!(y&1)){
        solve(x-(y>>1), y);
        mn = min(mn, dp[hsh(x-(y>>1),y)].first);
        mx = max(mx, dp[hsh(x-(y>>1),y)].second);
    }

    //might be able to get rid of this one 
        
    if(x == (y<<1)){
        solve(x-(y<<1),y);
        mn = min(mn, dp[hsh(x-(y<<1),y)].first);
        mx = max(mx, dp[hsh(x-(y<<1),y)].second);
    }        

    mn++;
    mx++;
    
}



int main(){
    //shouldnt make a difference
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    if(n < m) swap(n,m);

   
    solve(n,m);
    cout << dp[hsh(n,m)].first << " " << dp[hsh(n,m)].second << "\n";
}