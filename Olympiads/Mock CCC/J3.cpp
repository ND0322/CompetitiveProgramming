#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 2e5+5;

int n, k;

long long m, a[MAXN];
map<long long,int> ind;


int main(){
    cin >> n >> k >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i =0; i < n; i++){
        long long x; cin >> x;
        ind[x] = i;
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(ind.find(m-a[i]) == ind.end()) continue;

        ans += (abs(ind[m-a[i]] - i) >= k);
    }

    cout << ans << "\n";
}