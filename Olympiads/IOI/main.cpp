#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 205;

int dp[MAXN][MAXN][MAXN];

//current i, how many taken

long long get_cost(vector<int> a, vector<int> b){

    multiset<int> s;

    for(int i = 0; i < a.size(); i++) s.insert(a[i]);


    multiset<int> t;
    for(int i = 0; i < b.size(); i++){
        if(t.find(-a[b[i]]) != t.end()) t.erase(t.find(-a[b[i]]));
        else t.insert(a[b[i]]);
        s.erase(s.find(a[b[i]]));
    }

    //we can move back into a
    a.clear();
    b.clear();

    for(int i : s) a.push_back(i);
    for(int i : t) b.push_back(-i);

    sort(b.begin(), b.end());

    int n = (int)a.size()-1;
    int m = (int)b.size()-1;

    if(!m) return 0;
    if(m > n) return -1;

    //dp time!
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= m; k++) dp[i][j][k] = 1e9;
        }
    }
    
    for(int l = n; l >= 0; l--){
        for(int r = l; l <= n; r++){
            for(int k = 0; k <= m; k++){
                if(l == r){
                    if(k == m-1) dp[i][j] = abs(a[l] - b[k]);
                    continue;
                }

                if(r == l+1){
                    if(k == m) dp[i][j] = abs(a[l] + a[r]);
                    continue;
                }

                //left to b

                if(k < m) 
            }
        }
    }


}


int main(){
    cout << get_cost({1, 2, 2, 3}, {}) << "\n";
}