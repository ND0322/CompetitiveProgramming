#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4005;
const long long INF = 1e18;

typedef pair<int,int> pii;

int n,m,a[MAXN],b[MAXN];

long long dp[MAXN][MAXN];

pii nxt[MAXN][MAXN];

void rebuild(int i, int j, int cur){

    if(i == n) return;
    cout << cur << " ";

    if(nxt[i][j].second == j+1) cur++;

    rebuild(nxt[i][j].first,nxt[i][j].second,cur);
}

/*
long long solve(int i,int j){
    if(i == n && j == m){
        return 0;
    }
    
    if(i == n && j != m) return INF;

    if(dp[i][j] == -1){
        long long opt1 = solve(i+1,j+1),opt2 = solve(i+1,j);

        //if(i == 2 && j == 1) cout << abs(a[i] - b[j]) << "\n";

        dp[i][j] = min(opt1,opt2) + abs(a[i] - b[j]);

        
        if(opt1 < opt2){
            nxt[i][j] = {i+1,j+1};
            dp[i][j] = opt1 + abs(a[i] - b[j]);
        }
        else{
            nxt[i][j] = {i+1,j};
            dp[i][j] = opt2 + abs(a[i] - b[j]);
        }
        

        


    }

    return dp[i][j];
}
*/







int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;

    for(int i = 0; i < m; i++) cin >> b[i];

    /*
     if(n == 5 && m == 3){
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
        for(int i = 0; i < m; i++) cout << b[i] << " ";
        cout << "\n";
    }
    */

   



    sort(a,a+n);
    sort(b,b+m);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = INF;
        }
    }

    
    dp[n][m] = 0;

    

    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            
            long long opt1 = dp[i+1][j+1],opt2 = dp[i+1][j];

            //simple transition

            //either assign the person the j and then consider new j or assign person to j without continuing

            if(opt1 < opt2){
                nxt[i][j] = {i+1,j+1};
                dp[i][j] = opt1 + llabs(a[i] - b[j]);
            }
            else{
                nxt[i][j] = {i+1,j};
                dp[i][j] = opt2 + llabs(a[i] - b[j]);
            }

        }
    }

    cout << dp[0][0] << "\n";
    

    
    
    rebuild(0,0,1);

    cout << "\n";

    
    

  

  

   //cout << dp[2][1] << "\n";



    
}
   
