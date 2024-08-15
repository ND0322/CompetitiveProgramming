#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

//for each i check state of all factors 
//greedy after that

const int MAXN = 4e6+5;

int n, q;

bool state[MAXN];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> n;

        for(int i = 1; i <= n; i++) state[i] = 0;

        string s; cin >> s;
        s = '.' + s;

        cin >> q;

        while(q--){
            int x; cin >> x;
            state[x] ^= 1;
        }

        /*
        0100
        0110
        0011
        0010
        */

        int ans = 0;
        for(int i = 1; i <= n; i++){
            bool on = (s[i] - '0');

            for(int j = 1; j * j <= i; j++){
                if(i % j) continue;
                //cout << i << " " << j << " " << on << " ";
                on ^= state[j];
                if(j != i/j) on ^= state[i/j];

                //cout << on << "\n";

               
            }
            if(!on) continue;

            ans++;
            state[i] ^= 1;
        }


        cout << "Case #" << _ << ": " << ans << "\n";
    }
}
