#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 20;

int n,m, a[MAXN];
set<long long> ans, pos;

long long b[MAXN];

void solve(int i, long long l, long long r){
   
    if(i == m){
        if(l == r) pos.insert(2*l);
        return;
    }

    solve(i+1, l + b[i], r);
    solve(i+1, l, r + b[i]);
    solve(i+1, l, r);
}

int main(){
    cin >> n >> m;

    for(int i = 0 ; i< n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    solve(0,0,0);

    for(long long i : pos){
        for(int j = 0; j < n; j++) ans.insert(a[j] + i);
    }

    for(long long i:ans) cout << i << "\n";

}