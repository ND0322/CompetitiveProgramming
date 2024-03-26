#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//split into blocks then knapsack

const int MAXN = 2005;

int n, c[MAXN];

vector<vector<int>> blocks;



bool dp[2005][1005], opt[MAXN][MAXN];

vector<vector<int>> a, b;

void rebuild(int i, int j){
    if(i >= blocks.size()) return;
    if(opt[i][j]){
        a.push_back(blocks[i]);
        rebuild(i+1, j-blocks[i].size());
    }
    else{
        b.push_back(blocks[i]);
        rebuild(i+1, j);
    }
}


int main(){
    cin >> n;

    for(int i = 0; i < 2*n; i++) cin >> c[i];

    int l = 0;
   

    while(l < 2*n){
        blocks.push_back(vector<int>());
        int tmp = c[l];
        blocks[blocks.size()-1].push_back(tmp);

        l++;
        while(l < 2*n && c[l] < tmp){
            blocks[blocks.size()-1].push_back(c[l]);
            l++;
        }

       
    }

    int m = blocks.size();

    dp[m][0] = 1;

    for(int i = m-1; i >= 0; i--){
        for(int j = 1; j <= n; j++){
            if(2*n - j >= blocks[i].size() && dp[i+1][j]){
                opt[i][j] = 0;
                dp[i][j] = 1;
            }

            if(j - blocks[i].size() >= 0 && dp[i+1][j-blocks[i].size()]){
                opt[i][j] = 1;
                dp[i][j] = 1;
            }
        }
    }

    if(!dp[0][n]){
        cout << "-1\n";
        return 0;
    }

    rebuild(0, n);



    for(vector<int> i : a){
        for(int j : i) cout << j << " ";
    }

    cout << "\n";

    for(vector<int> i : b){
        for(int j : i) cout << j << " ";
    }

    cout << "\n";

    

    

   

    //3 1
    //4
    //5 2
    //6
}