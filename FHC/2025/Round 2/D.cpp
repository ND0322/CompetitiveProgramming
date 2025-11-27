#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

/*
digit dp

keep track of digit sum mod k 

2025 * 2 * 2 * 25 

add states for 

sum satisfied?
leadng zeros?
currently summing? 
*/

const int MOD = 998244353;

int n, k, dp[2030][2][2][2][3][25];

string l, r;

int solve(int i, bool small, bool big,bool lead,int state, int sm, vector<int> st){
    if(i == n+1){
        if(state == 2){
            for(int j : st) cout << j;
            cout << "\n";
        }
        return state == 2;
    }
    
    
    if(dp[i][small][big][lead][state][sm] != -1) return dp[i][small][big][lead][state][sm];

    
    dp[i][small][big][lead][state][sm] = 0;
    for(int d = 0; d <= 9; d++){
        if(d > r[i] - '0' && !small) continue;
        if(d < l[i] - '0' && !big) continue;

        vector<int> tmp = st;
        tmp.push_back(d);

        if(d == k || (lead && !d)){
            if(state == 0) continue;
            dp[i][small][big][lead][state][sm] = (dp[i][small][big][lead][state][sm] + solve(i+1, small || (d < r[i] - '0'), big || (d > l[i] - '0'), lead || d, 2,0, tmp)) % MOD;
            continue;
        }
        
        if(state == 1){
            int nsm = (sm + d) % k;
            int nstate = 1;
            if(!nsm) nstate++;
            dp[i][small][big][lead][state][sm] = (dp[i][small][big][lead][state][sm] + solve(i+1, small || d < r[i] - '0', big || (d > l[i] - '0'), lead || d,nstate ,nsm, tmp)) % MOD;
        }

        //say we have to sum if we are placing something that is divisible or 0 
        
        if(state == 0 && (lead || d)){
            //we can start summing if not satisfied
            
            int nsm = d % k;
            int nstate = 1;
            if(!nsm) nstate++;
            
            dp[i][small][big][lead][state][sm] = (dp[i][small][big][lead][state][sm] + solve(i+1, small || (d < r[i] - '0'), big || (d > l[i] - '0'), lead || d, nstate,nsm, tmp)) % MOD;
            //cout << dp[i][small][big][sat][cur][sm] << "\n";
        }        

        if(state != 1){
            dp[i][small][big][lead][state][sm] = (dp[i][small][big][lead][state][sm] + solve(i+1, small || (d < r[i] - '0'), big || (d > l[i] - '0'),lead || d, state,0, tmp)) % MOD;

        }
    }

    return dp[i][small][big][lead][state][sm];
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> l >> r >> k;

        n = r.size();

        memset(dp, -1, sizeof(dp));


        r = '.' + r;

        string tmp = ".";

        for(int i = 1; i <= n-(int)l.size(); i++) tmp += '0';

        l = tmp + l;


        int ans = solve(1, 0, 0, 0,0, 0, {});


        cout << "Case #" << _ << ": " << ans << "\n";
    }
}