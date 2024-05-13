#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, k;

pair<int,int> segs[MAXN];

int main(){
    cin >> n >> k;


    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;

        segs[i] = {r,l};
    }

    sort(segs+1,segs+n+1);

    int cnt = 0;   
    long long ans = 0;

    
}