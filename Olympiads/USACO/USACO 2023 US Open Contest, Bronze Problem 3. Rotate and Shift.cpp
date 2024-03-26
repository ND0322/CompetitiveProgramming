#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,k,t, a[MAXN], ans[MAXN];

int main(){
    cin >> n >> k >> t;

    for(int i = 1; i <= k; i++) cin >> a[i];

    a[k+1] = n;

    for(int i = 1; i <= k; i++){
        for(int j = a[i]; j < a[i+1]; j++){
            int diff = a[i+1]-a[i];

            int nxt = ((j-a[i]-t) % diff + diff) % diff;

            ans[(a[i] + nxt + t) % n] = j;
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
    
}