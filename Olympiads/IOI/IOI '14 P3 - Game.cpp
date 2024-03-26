#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1505;

int cnt[MAXN];

void initialize(int n){

}
int hasEdge(int u, int v){
    //assuming u > v
    if(u < v) swap(u,v);

    cnt[u]++;
    return cnt[u] == u;
}