#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, k, ans;

pair<int,int> a[MAXN];


/*
keep track of the kth largest thing 
*/

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

    multiset<int> s;

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++){
        s.insert(a[i].second);

        if(s.size() > k) s.erase(s.begin());
        if(s.size() == k){
            ans = max(ans, *s.begin() - a[i].first);
        }
    }

    cout << ans << "\n";

}