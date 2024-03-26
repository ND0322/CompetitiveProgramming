#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, s,t,a[MAXN], psa[MAXN];

int main(){
    cin >> n >> s >> t;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + a[i];

    int l = 1;
    int r = n;
    int ans = 0;

    while(l <= r && t--){

       
        
        if(psa[min(l+s,n)] - psa[l] >= psa[r] - psa[max(r-s,0)]){
            ans += psa[l+s] - psa[l];
            l+=s;
        }
        else{
            ans += psa[r] - psa[r-s];
            r-=s;
        }
    }

    cout << ans << "\n";
}