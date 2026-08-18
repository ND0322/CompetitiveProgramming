#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int psa[MAXN][4], a[MAXN], b[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, q; cin >> n >> q;


        for(int i = 1; i <= n+1; i++){
            psa[i][0] = psa[i][1] = psa[i][2] = psa[i][3] = 0;
            a[i] = 0;
            b[i] = 0;
        }

        for(int i = 0; i < n; i++){
            char c; cin >> c;
            a[i+1] = c - '0';
        }

        for(int i = 0; i < n; i++){
            char c; cin >> c;
            b[i+1] = c - '0';
        }

        for(int i = 1; i <= n; i++){
            if(a[i] && b[i]) psa[i][0]++;
            if(!a[i] && !b[i]) psa[i][1]++;
            if(!a[i] && b[i]) psa[i][2]++;
            if(a[i] && !b[i]) psa[i][3]++;

            for(int j = 0; j < 4; j++) psa[i][j] += psa[i-1][j];
        }

        while(q--){
            int l,r; cin >> l >> r;

            int c[4];

            for(int j = 0; j < 4; j++) c[j] = psa[r][j] - psa[l-1][j];

            int d = min(c[2], c[3]);
            c[2] -= d;
            c[3] -= d;

            if(!c[2]) swap(c[2], c[3]);



            if(c[0] + c[1] >= c[2]) cout << "YES\n";
            else cout << "NO\n";

        }
    }
}