#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4+5;

int n;

long long ans = 0;

int query(int x){
    cout << "? " << x << "\n";
    int ans; cin >> ans;

    return ans;
}

void dac(int l, int r, int lo, int hi){
    if(lo == hi){
        ans += (r-l+1) * lo;
        return;
    }

    int mid = (lo+hi)>>1;
    int res = query(mid);

    dac(l, res, lo, mid);
    dac(res+1, r, mid+1,r);
}

int main(){
    cin >> n;

    dac(1,n, 0, 1e7);

    cout << ans << "\n";

}
