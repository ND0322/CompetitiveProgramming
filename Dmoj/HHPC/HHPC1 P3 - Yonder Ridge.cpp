#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

#define int long long
#define double long double

const int MAXN = 5005;

int n, k, m, q, a[MAXN], b[MAXN], v[MAXN];

double intersect(double m1, double b1, double m2, double b2){
    return (b1-b2)/(m2-m1);
}

int32_t main(){
    cin >> n >> m >> q >> k;

    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> v[i];

    while(q--){
        int x,s; cin >> x >> s;

        double me = (b[x] - a[x])/(double)m;

        long long ans = 0;

        for(int i = 1; i <= n; i++){
            if(i == x)continue;

            int sect = intersect(me, a[x], (b[i] - a[i])/(double)m, a[i])+1;
            int ot = sect-2;

            if(sect * (b[i] - a[i])/(double)m + a[i] > sect * me + a[x] && sect >= s && sect <= s+k) ans += v[i];
            else if(ot * (b[i] - a[i])/(double)m + a[i] > ot * me + a[x] && ot >= s && ot <= s+k) ans += v[i];
        }

        cout << ans << "\n";


    }
}

/*
try to solve a quickly
b go with your instinct instead of just sitting there
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/