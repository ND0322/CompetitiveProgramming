#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


const int MAXN = 2e5+5;

int n, ans[MAXN];

pair<int,pair<int,int>> upd[MAXN];
pair<pair<int,int>,pair<int,int>> ranges[MAXN];

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

/*
4 cases:

lj >= li && rj <= ri
lj <= li && rj >= ri
lj < li && rj <= ri, min(rj,ri) >= k + li
lj >= li && rj > ri, max(lj, li) <= ri - k

notice how these only depend on j for one part of the inequality
look for example at case 3
it is trivial to deal with all rj > ri, so assume rj < ri
count the number of rj such that rj >= some known value and rj < some known value + number of rj > some known value
range query wit coord comp

that sh too complicated

consider only segments with at least length k
complementary count

count all the things with 
rj < li+k
lj > ri-k
-lj < k-ri
with length at least k
*/

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> ranges[i].second.first >> ranges[i].second.second >> ranges[i].first.first;
        ranges[i].first.second = i;

        upd[i].first = ranges[i].second.second - ranges[i].second.first;
        upd[i].second = ranges[i].second;
    }

    sort(ranges+1, ranges+n+1);
    reverse(ranges+1,ranges+n+1);

    sort(upd+1, upd+n+1);
    reverse(upd+1,upd+n+1);

    int j = 1;

    ost l,r;

    int added = 0;

    for(int i = 1; i <= n; i++){
        int k = ranges[i].first.first;
        int id = ranges[i].first.second;
        auto [ll,rr] = ranges[i].second;

        while(j <= n && upd[j].first >= k){
            r.insert(upd[j].second.second);
            l.insert(upd[j].second.first);
            added++;
            j++;
        }

        ans[id] = added - r.order_of_key(ll+k) - 1;
        ans[id] -= added - l.order_of_key(rr-k+1);
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
    
}