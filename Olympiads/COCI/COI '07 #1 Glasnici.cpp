#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

double k, a[MAXN];

bool can(double x){
    double cur = a[0] + x;

    for(int i = 1; i < n; i++){
        //if the guy cant hear from cur return false
        if(cur + k < a[i]-x) return false;

        cur = min(cur+k, a[i]+x);
    }

    return true;
}

int main(){
    cin >> k;

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    double lo = 0.0;
    double hi = 1e9;
    double ans = 0.0;

    for(int i = 0; i <= 100; i++){
        double mid = (lo+hi)/2;

        if(can(mid)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    if(ans == -1.0) cout << 0.000 << "\n";
    else cout << setprecision(4) << fixed << ans << "\n";

   




}