#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4+5;

int n, a[7];

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin >> n;
    int ans = 0;


    fill(a+1,a+7,-1);
    int cur = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        cur = (cur+x)%7;

        if(a[cur] == -1) a[cur] = i;
        else ans = max(ans, i-a[cur]);
    }

    cout << ans << "\n";

}