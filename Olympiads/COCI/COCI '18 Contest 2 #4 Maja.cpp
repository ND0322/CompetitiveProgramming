#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


const int MAXN = 105;

vector<int> di = {1,-1,0,0}, dj = {0,0,1,-1};

int n, m, k, a[MAXN][MAXN], sx, sy;

//for each thing find the maximum value it can reach after k steps away
//so second dp for that
//that + knapsack
//both use the two dp array swapping method thing 


long long dist[MAXN][MAXN];

long long dfs(int x, int y){
    if(x == sx && y == sy) return 0;
    if(x <= 0 || y <= 0 || x > n || y > m) return -1e18;
    if(dist[x][y] != -1) return dist[x][y];

    for(int i = 0; i < 4; i++){
        int cx = x + di[i];
        int cy = y + dj[i];

        if(abs(sx - cx) + abs(sy - cy) < abs(sx - x) + abs(sy - y)) dist[x][y] = max(dist[x][y], dfs(cx,cy));
    }

    dist[x][y] += a[x][y];
    return dist[x][y];
    

}
int32_t main(){
    cin >> n >> m >> sx >>sy >> k;

    for(int i = 1; i <= n; i++){
        for(int j =1; j <= m; j++) cin >> a[i][j];

    }


    memset(dist, -1, sizeof(dist));

    dist[sx][sy] = 0;


    //64 + 9 + 8
    

    long long ans = 0; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if((abs(sx - i) + abs(sy - j)) * 2 > k) continue;

            int d = abs(sx - i) + abs(sy - j);
            

            ans = max(ans, 2 * dfs(i,j) - a[i][j] + ((k-d*2)/2) * a[i][j] + ((k-d*2)/2) * max({a[i+1][j], a[i-1][j], a[i][j+1], a[i][j-1]}));
        

           
        }
    }

    cout << ans << "\n";

}