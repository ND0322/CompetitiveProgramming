#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e6+5;

#define int long long

int n, k, a[MAXN], b[MAXN], psa[MAXN];

multiset<int> s, ps;


/*
num things where psa[r] - psa[i-1] < 0
psa[r] < psa[i-1]

that can be done with sets and bsearch
-2 -5 - 4
*/

int32_t main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++) psa[i] = psa[i-1] + b[i] - a[i];

    int r = 0;
    int ans = 0;
    int sm = 0;

    for(int i = 1; i <= n; i++){
        r = max(r, i-1);
        cout << i << " " << r+1 << " " << sm << " " << k + sm + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]) << " " << max((s.size() == 0 ? 0 :*s.rbegin()), a[r+1] - (b[r+1] < a[r+1]) * (b[r+1] - a[r+1])) << "\n";

        while(r < n && k + sm + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]) >= max((s.size() == 0 ? 0 :*s.rbegin()), a[r+1] - (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]))){
            //cout << i << " " <<r+1 << " " << k + sm + (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]) << " " << max((s.size() == 0 ? 0 :*s.rbegin()), a[r+1] - (b[r+1] < a[r+1]) * b[r+1])<< "\n";
            sm += (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]);
            s.insert(a[r+1] - (b[r+1] < a[r+1]) * (b[r+1] - a[r+1]));
            ps.insert(psa[r+1]);
            r++;
        }

        ans += max(r-i+1, 0LL);

        cout << i << " " << r << "\n";

        for(int j = i; j <= r; j++){
            ans -= (psa[j] < psa[i-1]);
        }

        if(r >= i){
            sm -= (b[i] < a[i]) * (b[i] - a[i]);
            s.erase(s.find(a[i] - (b[i] < a[i]) * (b[i] - a[i])));
        }
        
    }

    cout << ans << "\n";
}