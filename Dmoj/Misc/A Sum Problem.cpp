#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4+5;

int n; 

int query(int x){
    cout << "? " << x << "\n";
    int ans; cin >> ans;

    return ans;
}

int main(){
    cin >> n;

    int cnt = 0;
    int x = 0;

    int cur = query(0);
    long long ans = 0;

    while(cnt < n){
        int lo = x+1;
        int hi = 1e7;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(cur != query(mid)){
                hi = mid-1;
                ans = mid;
            }
            else ans = mid+1;
        }

        int tmp = query(ans);

        ans += ans * (cur - tmp);
        cnt += cur - tmp;
        cur = tmp;
    }

    cout << "! " << ans << "\n";
}
