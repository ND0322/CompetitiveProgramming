#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, par[MAXN];

vector<int> sub[MAXN];

int find(int x){
    return x == par[x] ? x : find(par[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(sub[x].size() < sub[y].size()) swap(x,y);
    par[y] = x;
    for(int i : sub[y]) sub[x].push_back(i);
    
    
}

int main(){
    cin >> n;

    for(int i =1 ; i <= n; i++){
        par[i] = i;
        sub[i].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        int x,y; cin >> x >> y;

        uni(x,y);
    }

    for(int i : sub[find(1)]) cout << i << " ";
    cout << "\n";
}