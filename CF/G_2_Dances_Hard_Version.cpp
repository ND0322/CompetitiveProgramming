#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 1e5+5;

//binary search over m

int n, m, a[MAXN], b[MAXN], c[MAXN];

int f(long long x){
    int big = 0;
    c[0] = x;
    for (int i = 1; i < n; i++) c[i] = a[i];
    sort(c, c + n);
    sort(b, b + n);


    for (int i = 0; i < n; i++) {
        int upper = upper_bound(b, b + n, c[i]) - b;
        big = max(big, upper - i);
    }
    return big;
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        long long ans = f(1);

        long long lo = 1;
        long long hi = m+1;


        while(lo < hi-1){
            long long mid = (lo+hi)/2;

            if(f(mid) == ans) lo = mid;
            else hi = mid;
        }


        cout << ans * lo + (ans+1) * (m-lo) << "\n";






    }
}
