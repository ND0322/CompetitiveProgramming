#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 305;

int n, a,b,c;

double dp[MAXN][MAXN][MAXN];

double solve(int x, int y, int z){
    if(x < 0 || y < 0 || z < 0) return 0;
	if(!x && !y && !z) return 0;

    if(dp[x][y][z] > 0) return dp[x][y][z];
    
    
    dp[x][y][z] = (long double)((n + x * solve(x-1, y, z) + y * solve(x+1,y-1, z) + z * solve(x,y+1,z-1))) / (x+y+z);
    
    
    return dp[x][y][z];
   
    
    //adding 1 to the second 2 cases because those dishes are created
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        if(x == 1) a++;
        if(x == 2) b++;
        if(x == 3) c++;
    }

    memset(dp, -1, sizeof(dp));

    

    cout << setprecision(10) << fixed << solve(a,b,c) << "\n";


}