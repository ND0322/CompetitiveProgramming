#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int dp[25][2][2][11][10][2], rebuild[25][2][2][11][10][2], n, l[25], r[25];
string ans;

//dont count leading 0s

int solve(int i, bool lo, bool hi, int mn, int mx, bool placed){
    if(i == n+1){
        if((mx == mn) && mn == 0) return 1e9;
        return (mx - mn);
    }

    if(dp[i][lo][hi][mn][mx][placed] != -1) return dp[i][lo][hi][mn][mx][placed];


    dp[i][lo][hi][mn][mx][placed] = 1e9;

    for(int j = 0; j < 10; j++){
        if(!lo && j > r[i]) continue;
        if(!hi && j < l[i]) continue;
        if(!placed && j == 0){

            if(solve(i+1, lo | (j < r[i]), hi | (j > l[i]), mn, mx, placed) < dp[i][lo][hi][mn][mx][placed])
            dp[i][lo][hi][mn][mx][placed] = solve(i+1, lo | (j < r[i]), hi | (j > l[i]), mn, mx, placed); 
            rebuild[i][lo][hi][mn][mx][placed] = j;
        }
        else{
            if(solve(i+1, lo | (j < r[i]), hi | (j > l[i]), min(mn, j), max(mx, j), placed | (j != 0)) < dp[i][lo][hi][mn][mx][placed]){
                dp[i][lo][hi][mn][mx][placed] = min(dp[i][lo][hi][mn][mx][placed], solve(i+1, lo | (j < r[i]), hi | (j > l[i]), min(mn, j), max(mx, j), placed | (j != 0)));
                rebuild[i][lo][hi][mn][mx][placed] = j;
            }
        }
    }

    return dp[i][lo][hi][mn][mx][placed];
}

void build(int i, bool lo, bool hi, int mn, int mx, bool placed){
    if(i == n+1) return;

    int j = rebuild[i][lo][hi][mn][mx][placed];

    
    if(!(!placed && j == 0)) cout << j << "";

    if(!placed && j == 0) build(i+1, lo | (j < r[i]), hi | (j > l[i]), mn, mx, placed);
    else build(i+1, lo | (j < r[i]), hi | (j > l[i]), min(mn, j), max(mx, j), placed | (j != 0));
              
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        string a, b; cin >> a >> b;


        n = b.size();

        for(int i = 1; i <= n; i++) r[i] = b[i-1] - '0';
        

        
        for(int i = 1; i <= a.size(); i++) l[(int)b.size() - (int)a.size() + i] = a[i-1] - '0';


        memset(dp, -1, sizeof(dp));

        ans = "";

        solve(1,0,0,10,0,0);

        build(1,0,0,10,0,0);
         
        cout << "\n";
        
        for(int i = 1; i <= n; i++) l[i] = r[i] = 0;


    }
}