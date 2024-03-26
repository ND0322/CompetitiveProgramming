#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include "inaho.h"

using namespace std;

const int MAXN = 5e5+5;

int parents[MAXN], sz[MAXN];
stack<pair<pair<int,int>,int>> hist;

void Init(int N){
    for(int i = 1; i <= N; i++){
        parents[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    return x == parents[x] ? x : find(parents[x]);
}


void AddEdge(int U, int V){
    U = find(U);
    V = find(V);

    if(U == V){
        hist.push({{-1,-1},-1});
        return;
    }

    if(sz[U] < sz[V]) swap(U,V);
    hist.push({{U,V}, sz[U]});
    parents[V] = U;
    sz[U] += sz[V];
    

}


void RemoveLastEdge(){
    if(hist.top().first.first != -1){
        parents[hist.top().first.second] = hist.top().first.second;
        sz[hist.top().first.first] = hist.top().second;
    }

    hist.pop();
}
int GetSize(int U){
    return sz[find(U)];
}