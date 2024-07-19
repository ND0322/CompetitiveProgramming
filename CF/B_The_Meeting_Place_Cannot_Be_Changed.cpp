#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 6e4+5;

int n;

long double a[MAXN], b[MAXN];

long double f(long double x){
    x/=1e6;
    long double ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, abs(x-a[i])/(long double)b[i]);
    return ans;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    long long lo = 1e6;
    long long hi = 1e15;
    double ans = 0;

    while(lo <= hi){
        long long mid = (lo+hi)>>1;

        if(f(mid) < f(mid+1)){
            hi = mid-1;
            ans = f(mid);
        }
        else lo = mid+1;
    }



    cout << setprecision(6) << fixed << ans << "\n";


}