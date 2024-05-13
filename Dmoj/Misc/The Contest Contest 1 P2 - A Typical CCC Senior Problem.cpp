#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long


const int MAXN = 1e6+5;

int n, k, a[MAXN], x[MAXN], ans[MAXN], upd[MAXN], r[MAXN];

long long psa[MAXN];


set<int> ind[MAXN];




int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    long long sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];

        sum += a[i];
        psa[i] = psa[i-1] + a[i];
        ind[a[i]].insert(i);
    }

    for(int i = 1; i <= k; i++){
        cin >> x[i];
        ans[i] = sum;
    }

    for(int i = n; i >= 1; i--){
        auto it = ind[a[i]].lower_bound(i);

        upd[i] += x[a[i]];

        r[i] = max(r[i], i);
        //cout << i << " " << upd[i] << " " << r[i] << "\n";
        if(it == ind[a[i]].begin()){
            ans[a[i]] -= psa[r[i]] - psa[max(i-upd[i], 1LL)-1];
            continue;
        }
        it--;



        if(*it >= i-upd[i]){
            upd[*it] += upd[i] - (i - *it)+1;
            r[*it] = r[i];
            continue;
        }

        ans[a[i]] -= psa[r[i]] - psa[max(i-upd[i], 1LL)-1];
    }

    //process right to left
    //stack updates onto the next one if theres an intersect


    for(int i = 1; i <= k; i++) cout << ans[i] << "\n";
    



}


/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/