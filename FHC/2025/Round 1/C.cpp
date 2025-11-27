#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited

/*
an must equal prefix xor
just dp transitioning to the next point where prefix xor == ai 
*/

const int MAXN = 1e6+5;

int n, a[MAXN], pxr[MAXN];




int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        map<int,int> d;
        map<int,int> cnt;

        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pxr[i] = pxr[i-1] ^ a[i];
        }

        int ans = 0;
        //of all those with equal xor to i+1
        //only subtract contribution with equal prefix xor

        for(int i = n; i >= 1; i--){

            cnt[pxr[i]]++;
            d[pxr[i]] += cnt[pxr[i]];

            ans += ((n-i+1) * (n-i+2))/2 - d[pxr[i-1]];
        }


        cout << "Case #" << _ << ": " << ans << "\n";
    }
}