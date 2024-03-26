#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string s;
int n;

const int INF = 1e9;

vector<unordered_map<string,int> > dp;

int solve(int i, string cur){
    if(i == n){
        string forward = cur;
        reverse(cur.begin(),cur.end());

        if(cur != forward){
            return cur.size();
        }
        return -1;
    }

    if(dp[i].find(cur) == dp[i].end()){
        dp[i][cur] = max(solve(i+1,cur),solve(i+1,cur+s[i]));
    }
    return dp[i][cur];

        
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t; cin >> t;

    while(t--){
        cin >> s;
        n = s.size();

        dp = vector<unordered_map<string,int> >(n,unordered_map<string,int>());
        
        cout << solve(0,"") << "\n";
    }
}