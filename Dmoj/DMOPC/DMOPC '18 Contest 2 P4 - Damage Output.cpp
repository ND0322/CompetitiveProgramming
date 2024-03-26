#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int n, a[MAXN];

long long psa[MAXN], k;

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }

    int ans = 1e9;
    for(int i= 1; i <= n; i++){
        int lo = i;
        int hi = n;
        int res = 1e9;

        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(psa[mid] - psa[i-1] >= k){
                res = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        ans = min(ans, res - i + 1);
    }

    cout << (ans > n ? -1 : ans) << "\n";
}