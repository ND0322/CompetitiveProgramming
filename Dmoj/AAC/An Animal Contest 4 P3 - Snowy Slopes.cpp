#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

using namespace std;

#define int long long

const int MAXN = 1e5+5;

int n, m, px[MAXN], py[MAXN];

set<pair<int,int>> s;

/*
    (y2 - y1)/(x2-x1) = k/d
    d(y2 - y1) = k(x2-x1)
    dy2 - dy1 = kx2 - kx1
    dy2 - kx2 = dy1 - kx1

    cnt freq + combinations

    for each k and d


*/

int gcd(int a, int b){
    return !b ? a : gcd(b,a%b);
}


int32_t main(){
    cin >> n >> m;


    long long ans = 0;

    for(int i = 0; i < n; i++) cin >> px[i] >> py[i];


    

    for(int i = 0; i < m; i++){
        int k,d; cin >> k >> d;

        int g = gcd(k,d);

        k /= g;
        d /= g;


        if(s.find({k,d}) != s.end()) continue;
        s.insert({k,d});

        map<int, int> things;

        for(int i = 0; i < n; i++) things[d*py[i] - k*px[i]]++;

        for(auto [i,j] : things){
            ans += (j >= 2 ? j * (j-1) / 2 : 0);
            //cout << k << " " << d << " " << i << " " << j << "\n";
        }

        
    }

    

    cout << ans << "\n";



}