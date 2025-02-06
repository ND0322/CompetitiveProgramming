#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int n; cin >> n;

    vector<int> a(n+1);
    vector<int> pre(n+1);
    vector<int> suf(n+2);

    for(int i = 1; i <= n; i++) cin >> a[i];

    pre[0] = (1<<31)-1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0) pre[i] = pre[i-1] & 1;
        else pre[i] = pre[i-1] & (a[i] ^ ((1<<(int)ceil(log2(a[i])))-1));
    }


    suf[n+1] = (1<<31)-1;
    for(int i = n; i >= 1; i--){
        if(a[i] == 0) suf[i] = suf[i+1] & 1;
        else suf[i] = suf[i+1] & (a[i] ^ ((1<<(int)ceil(log2(a[i])))-1));
    }

    pair<int,int> ans = {0,0};

    for(int i = 1; i <= n; i++) ans = max(ans, {pre[i-1] & suf[i+1] & a[i], i});

    cout << a[ans.second] << " ";

    for(int i = 1; i <= n;i++){
        if(i == ans.second) continue;
        cout << a[i] << " ";
    }
}