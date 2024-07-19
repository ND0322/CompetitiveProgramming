#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 1e9+7;

int n;

long long a[MAXN], b[MAXN], k;

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];   
    
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    


    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    reverse(a+1,a+n+1);
    reverse(b+1,b+n+1);

    long long ans = 0; 

    for(int i = 2; i <= n; i++) ans = (ans + (a[i] * b[i]) % MOD) % MOD;

    if(a[1] > b[1]) swap(a[1], b[1]);

    long long tmp = b[1] - a[1];
    a[1] += min(k, tmp);

    k -= min(k,tmp);

   

    a[1] += k/2;
    b[1] += k/2 + (k&1);

    ans = (ans + (a[1] * b[1]) % MOD) % MOD;

    cout << ans << "\n";
}