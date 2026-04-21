#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, a[MAXN];
void sub1(int tt){
    sort(a+1, a+n+1);

    int ans = 0;

    for(int i = 1; i < n; i++) ans = max(ans, a[i+1] - a[i]);
    cout << "Case #" << tt << ": " << ans << "\n";
}

int main(){

    int tt; cin >> tt;

    for(int _ = 0; _ < tt; _++){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        sub1(_);
    }

    

    /*
    line is just sort array
    circle is first increasing then decreasing 

    */
}