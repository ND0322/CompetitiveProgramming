#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 1e9+7;

int n, k, a[MAXN];

multiset<int> s;

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++){
        s.erase(s.find(a[i]));

        ans += s.lower_bound(k-a[i]+1) - s.begin();

    }


    
}