#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, parents[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    parents[x] = y;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) parents[i] = i;

    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;

        uni(x,y);
    }

    int x,y; cin >> x >> y;

    cout << (find(x) == find(y) ? "Tangled\n" : "Not Tangled\n");
}