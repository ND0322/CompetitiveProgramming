#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1005;

int n, lx, ly;


int main(){
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    cin >> n;

    set<pair<pair<int,int>,pair<int,int>>> edges;
    set<pair<int,int>> nodes;

    int ans = 0;

    nodes.insert({lx,ly});

    for(int i = 0; i< n; i++){
        int x= lx;
        int y= ly;

        char act; cin >> act;

        if(act == 'N') x++;
        if(act == 'S') x--;
        if(act == 'E') y--;
        if(act == 'W') y++;
        
        pair<pair<int,int>,pair<int,int>> tmp = {{x,y},{lx,ly}};

        if(edges.find(tmp) == edges.end() && nodes.find({x,y}) != nodes.end()) ans++;

        edges.insert(tmp);  
        swap(tmp.first, tmp.second);
        edges.insert(tmp);
        nodes.insert({x,y});

        lx = x;
        ly = y;
    }

    cout << ans << "\n";

   

}