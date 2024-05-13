#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ost;

typedef long long ll;

const int MAXN = 1e5+5;

int n, psa[MAXN];

/*
consider what happens in a operation
1: ai-1 += ai
2:ai+1 += ai
3: ai += -2ai

2 1 0 5 7 5 14

if we build a psum we just check if its possible to sort it using some operations
psa[1] must be non negative

operating on index i
all things before dont matter
psa[i-1] += a[i]
psa[i] += -2a[i] + a[i] = -a[i]
psa[i+1] += a[i] - a[i] = 0
all things after dont get contribution

so in one operation:
psa[i-1] += a[i] = psa[i] - psa[i-1]
psa[i] += -a[i] = -(psa[i] - psa[i-1])

psa[i-1] = psa[i]
psa[i] = psa[i-1]

so they just swap
*/

int32_t main() {
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    
    for(int i = 1; i <= n; i++){
        if(psa[i] < 0 || psa[i] > psa[n]){
            cout << "-1\n";
            return 0;
        }
    }
    ost t;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans += i - t.order_of_key({psa[i], i}) - 1;
        t.insert({psa[i], i});
    }

    cout << ans << "\n";
}

