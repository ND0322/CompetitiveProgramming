#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN],psa[MAXN];



int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    cin >> n;

    for(int i = 0; i <n ;i++){
        int x; cin >> x;

        if(x <= 0) a[i] = 1;
        if(x >= 0) psa[i] = 1;
    }

    for(int i =1; i < n; i++){
        psa[i] += psa[i-1];
        a[i] += a[i-1];
    }

    int ans = MAXN;

    for(int i = 0; i < n-1; i++){
        ans = min(ans,psa[i] + a[n-1] - a[i]);
    }

    cout << ans << "\n";

    
}