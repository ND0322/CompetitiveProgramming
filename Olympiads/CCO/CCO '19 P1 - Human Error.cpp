#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;


int n,m, k1, k2, grid[15][15];

map<long long, double> dp[2];

vector<int> di = {0, -1, 0, 1}, dj = {1, 0, -1, 0};


//3^0 spot is top row
void decode(long long x){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            grid[i][j] = x % 10;
            x /= 10;
        }
    }
}

long long encode(){
    long long x = 0;
    long long base = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            x += grid[i][j] * base;
            base *= 10;
        }
    }
    return x;
}

void solve(long long x, bool p){
    if(dp[p].find(x) != dp[p].end()) return;

    //p == 1 -> Justin
    decode(x);

    vector<double> s;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j] - 1 != p) continue;
            
            for(int k = 0; k < 4; k++){
                if(!grid[i + di[k]][j + dj[k]]) continue;
                
                int tmp = grid[i+di[k]][j+dj[k]];

                grid[i+di[k]][j+dj[k]] = p+1;
                grid[i][j] = 0;
                long long state = encode();
                solve(state, !p);
                grid[i][j] = p+1;
                grid[i+di[k]][j+dj[k]] = tmp;

                s.push_back(dp[!p][state]);
            }
        }
    }

    //justin takes the best k1
    //donald takes the worst k2

    if(p && s.empty()){
        dp[p][x] = 0;
        return;
    }
    if(!p && s.empty()){
        dp[p][x] = 1;
        return;
    }


    if(p){
        int tot = min(k1, (int)s.size());
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        for(int i = 0; i < tot; i++) dp[p][x] += 1/(double)tot * s[i];
    }
    else{
        int tot = min(k2, (int)s.size());
        sort(s.begin(), s.end());
        for(int i = 0; i < tot; i++) dp[p][x] += 1/(double)tot * s[i];
    }    
}



int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        for(int j = 1; j <= m; j++){
            char c = s[j-1];

            if(c == 'J') grid[i][j] = 2;
            if(c == 'D') grid[i][j] = 1;
            if(c == '_') grid[i][j] = 0;
        }
    }


    cin >> k1 >> k2;


    long long state = encode();



    decode(state);


    solve(state, 1);

    

    cout << fixed << setprecision(3) << dp[1][state] << "\n";




}
