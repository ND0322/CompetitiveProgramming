#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 105;

int n,m;

string s,t;

bool vis[MAXN][MAXN], dp[MAXN][MAXN];

bool solve(int i, int j, string t){
    
    if(i == n+1 && j >= (int)t.size()) return 1;
    if(i < n+1 && j >= (int)t.size()) return 0;
    if(vis[i][j]) return dp[i][j];

    dp[i][j] = 0;
    

    if(j < t.size()-1 && t[j+1] == 'n'){
        for(int k = i; k <= n; k++){
            if(s[k] != t[j]) break;
            dp[i][j] |= solve(k+1, j+2, t);
        }

        dp[i][j] |= solve(i, j+2, t);
    }
    else{
        if(s[i] != t[j]) dp[i][j] = 0;
        else dp[i][j] = solve(i+1, j+1, t);
    }

    vis[i][j] = 1;
    return dp[i][j];
}

bool check(string t){
    if(t[1] == 'n') return 0;
    for(int i = 2; i <= t.size(); i++){
        if(t[i] == 'n' && t[i-1] == 'n') return 0;
    }
    return 1;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        cin >> s;

        s = '.' + s;

        cin >> m;
        cin >> t;
        t = '.' + t;

        vector<string> cand;

        for(int i = 1; i <= m; i++){
            string p = t.substr(0, i) + 'F' + t.substr(i+1);

            if(check(p)) cand.push_back(p);
            p = t.substr(0, i) + 'O' + t.substr(i+1);
            if(check(p)) cand.push_back(p);

            p = t.substr(0, i) + 'X' + t.substr(i+1);
            if(check(p)) cand.push_back(p);

            p = t.substr(0, i) + 'n' + t.substr(i+1);
            if(check(p)) cand.push_back(p);

            p = t.substr(0, i) + t.substr(i+1);
            if(check(p)) cand.push_back(p);

            p = t.substr(0, i) + 'F' + t.substr(i);
            if(check(p)) cand.push_back(p);

            p = t.substr(0, i) + 'O' + t.substr(i);
            if(check(p)) cand.push_back(p);

            p = t.substr(0, i) + 'X' + t.substr(i);
            if(check(p)) cand.push_back(p);            
        }

        string p = t.substr(0, m+1) + 'F';
        if(check(p)) cand.push_back(p);       

        p = t.substr(0, m+1) + 'O';
        if(check(p)) cand.push_back(p);     

        p = t.substr(0, m+1) + 'X';
        if(check(p)) cand.push_back(p);    

        p = t.substr(0, m+1) + 'n';
        if(check(p)) cand.push_back(p);     


        bool ans = 0;
        for(string s:cand){
            memset(vis, 0, sizeof(vis));
            if(solve(1,1, s)){
                ans = 1;
                break;
            }
        }

        cout << (ans ? "Yes\n" : "No\n");
    }
}