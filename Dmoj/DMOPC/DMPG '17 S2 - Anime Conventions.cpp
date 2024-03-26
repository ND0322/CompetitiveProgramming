#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,q, parents[MAXN];

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

    if(x == y) return;

    parents[x] = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);


    cin >> n >> q;

    for(int i = 1; i <= n; i++) parents[i] = i;

    while(q--){
        char t; cin >> t;

        if(t == 'A'){
            int x,y; cin >> x >> y;

            uni(x,y);
        }
        else{
            int x, y; cin >> x >> y;

            cout << (find(x) == find(y) ? 'Y' : 'N') << "\n";
        }
    }
}