#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n, a[MAXN], e[3];
int main(){
    cin >> e[0] >> e[1] >> e[2];

    cin >> n;

    long long ans = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n; i++){
        ans += e[a[i]];

        //cout << e[0] << " " << e[1] << " " << e[2] << "\n";

        int cnt[3] = {n,n,n};

        

        for(int j = n-1; j >= i+1; j--) cnt[a[j]] = j;

        if(a[i] == 0) e[(cnt[1] > cnt[2] ? 1 : 2)] += e[a[i]];
        if(a[i] == 1) e[(cnt[2] > cnt[0] ? 2 : 0)] += e[a[i]];
        if(a[i] == 2) e[(cnt[1] > cnt[0] ? 1 : 0)] += e[a[i]];

        e[a[i]] = 0;
    }

    cout << ans << "\n";
}