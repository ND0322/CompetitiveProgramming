#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 205;

int A,B,C, dp[MAXN][MAXN][MAXN];

vector<int> sticks[3];

int solve(int a,int b, int c){
    
}

int main(){
    cin >> A >> B >> C;

    for(int i = 0; i < A; i++){
        int x; cin >> x;
        sticks[0].push_back(x);
    }

    for(int i = 0; i < B; i++){
        int x; cin >> x;
        sticks[1].push_back(x);
    }

    for(int i = 0; i < C; i++){
        int x; cin >> x;
        sticks[2].push_back(x);
    }

    sort(sticks[0].rbegin(), sticks[0].rend());
    sort(sticks[1].rbegin(), sticks[1].rend());
    sort(sticks[2].rbegin(), sticks[2].rend());
}