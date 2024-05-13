#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//# of peaks - some case by case stuff
//a[i] > a[i+1]

const int MAXN = 1e5+5;

int n, q, a[MAXN];


int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i < n; i++) psa[i] = psa[i-1] + (a[i] > a[i+1]);
    while(q--){
        int l,r; cin >> l >> r;

        int cnt = psa[r] - psa[l-1];

        
    } 
}