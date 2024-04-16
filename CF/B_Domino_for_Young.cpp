#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

#define int long long

int n, a[MAXN], cnt, ans;

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n ;i++){
        cin >> a[i];
        ans += a[i];
    }

    for(int i = 1; i <= n+1; i++){

        while(cnt > a[i]){
            cnt-=2;
            ans--;
        }

        if((a[i] - cnt)&1) cnt++;
        else cnt = max(0LL, cnt-1);
    }

    cout << ans/2 << "\n";


}