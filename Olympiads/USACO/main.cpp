#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

#define int long long

const int MAXN = 45;

int n, x[MAXN], y[MAXN], ans[MAXN];

map<pair<int,int>,int> mpl[MAXN], mpr[MAXN];

int32_t main(){
    cin >> n;

    int tx, ty; cin >> tx >> ty;

    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for(int i = 0; i <= n/2; i++){
        vector<int> bits;

        for(int j = 0; j < n/2-i; j++) bits.push_back(0);
        for(int j = 0; j < i; j++) bits.push_back(1);

        do{
            int sx = 0;
            int sy = 0;

            for(int k = 0; k < n/2; k++){
                sx += x[k] * bits[k];
                sy += y[k] * bits[k];
            }

            mpl[i][{sx,sy}]++;
        }
        while(next_permutation(bits.begin(), bits.end()));
    }

    for(int i = 0; i <= n-n/2; i++){
        vector<int> bits;

        for(int j = 0; j < n-n/2-i; j++) bits.push_back(0);
        for(int j = 0; j < i; j++) bits.push_back(1);

        do{
            int sx = tx;
            int sy = ty;

            for(int k = n/2; k < n; k++){
                sx -= x[k] * bits[k-n/2];
                sy -= y[k] * bits[k-n/2];
            }

            mpr[i][{sx,sy}]++;
        }
        while(next_permutation(bits.begin(), bits.end()));
    }

    for(int i = 1; i <= n; i++){
        long long ans = 0;


        for(int j = 0; j <= i; j++){
            for(auto k : mpl[j]) ans += k.second * mpr[i-j][k.first];
        }
        

        cout << ans << "\n";

    }
}