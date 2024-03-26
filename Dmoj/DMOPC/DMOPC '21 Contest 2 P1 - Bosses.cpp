#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    long long h,p; cin >> n >>h >> p;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long ans = h * a[n-1];
    long long tot = 0;
    long long cnt = 0;
    for(int i = n-1; i >= 0; i--){
        tot += a[i];
        if(!i){
            cnt = 0;
            ans = min(ans, p * tot);
        }
        else{
            cnt = a[i-1];
            ans = min(ans, h * cnt + p * (tot - cnt * (n-i)));
        }

       
    }

    cout << ans << "\n";


}