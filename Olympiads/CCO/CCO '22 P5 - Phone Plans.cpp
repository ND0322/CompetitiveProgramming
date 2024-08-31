#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 5e5+5;

int parents[MAXN][3], sz[MAXN][3];
stack<pair<pair<int,int>,int>> hist[3];

//smth like bruteforce num pairs on left and maximize num pairs on right
//right will be component size stuff of r - union which is roads <= min(la, lb)

//or process a in increasing l
//this way we can use one dsu for a and bsearch for b
//2p 
//process increasing l for a and keep pointer for b 
//at the start initilize a dsu rollback for b will all edges added and rollback for each pointer movement
//normal dsu for a


int find(int x, int t){
    return x == parents[x][t] ? x : find(parents[x][t], t);
}

void uni(int x, int y, int t){
    x = find(x, t);
    y = find(y, t);

    if(x == y){
        hist[t].push({{-1,-1},-1});
        return;
    }

    if(sz[x] < sz[y]) swap(x,y);
    hist[t].push({{x, y}, sz[x][t]});
    sz[x][t] += sz[y][t];
    parents[y][t] = x;
}

void rollback(bool t){
    if(hist[t].top().first.first != -1){
        parents[hist[t].top().first.second][t] = hist[t].top().first.second;
        sz[hist[t].top().first.first][t] = hist[t].top().second;
    }

    hist[t].pop();
}

int main(){

}