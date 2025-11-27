#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n+1);
    vector<bool> vis(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int lo = 0;
    int hi = n/2;

    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        bool flag = 1;

        for(int i = 1; i <= mid; i++) flag &= (a[n-mid+i] >= 2 * a[i]);
        

        if(flag){
            lo = mid+1;
            ans = mid;
        }
        else hi = mid-1;
    }

    cout << n-ans << "\n";
}