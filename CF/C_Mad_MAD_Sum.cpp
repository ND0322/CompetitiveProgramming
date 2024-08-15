#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n;

long long a[MAXN], freq[MAXN];

//simulate twice
//after that the prefix will shrink 1 by 1 from left to right

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        long long sm = 0;

        long long mx = 0;

        for(int i = 1; i <= n; i++) freq[i] = 0;

        for(int i = 1; i <= n; i++){
            freq[a[i]]++;
            if(freq[a[i]] >= 2) mx = max(mx, a[i]);
            sm += a[i];
            a[i] = mx;
        }

        mx = 0;
        for(int i = 1; i <= n; i++) freq[i] = 0;

        for(int i = 1; i <= n; i++){
            freq[a[i]]++;
            if(freq[a[i]] >= 2) mx = max(mx, a[i]);
            sm += a[i];
            a[i] = mx;
        }

        reverse(a+1,a+n+1);

        for(int i = 1; i <= n; i++) sm += a[i] * i;

        cout << sm << "\n";




    }
}