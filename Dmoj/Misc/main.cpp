#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

const int MAXN = 1e6+5;

int n, a[MAXN], k;

pair<int,int> dac(int l, int r, int i){
    if(r == l+1){
        int x, y;
        if(i == l) x = k;
        else x = a[l - (l > i)];

        if(i == r) y = k;
        else y = a[r-(r>i)];


        return {abs(x-y) * abs(x-y), max(x,y)};
    }

    int mid = (l+r)>>1;

    pair<int,int> ll = dac(l, mid, i);
    pair<int,int> rr = dac(mid+1, r, i);

    return {ll.first + rr.first + abs(ll.second - rr.second) *abs(ll.second - rr.second), max(ll.second, rr.second)};
}

int32_t main(){
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    for(int i = 1; i <= n-1; i++){
        cin >> a[i];

        s.erase(a[i]);
    }

    k = *s.begin();

    cout << dac(1,n, 1).first << "\n";
    cout << "\n";

    
}