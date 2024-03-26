#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>



using namespace std;
using namespace __gnu_pbds;

const int MAXN = 3e5+5;

typedef pair<int,int> pii;
typedef tree<int,null_type,less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

ost t;


int n,k;

pii a[MAXN];

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i].second >> a[i].first;
    }

    for(int i = 0; i < k; i++){
        int x; cin >> x;

        t.insert(x);
    }


    sort(a,a+n);
    
    reverse(a,a+n);

    long long ans = 0;

    for(int i = 0; i < n; i++){
        int x = t.order_of_key(a[i].second);

        if(x >= t.size()) continue;
        
        ans += a[i].first;
        t.erase(t.find_by_order(x));
    }

    cout << ans << "\n";
}