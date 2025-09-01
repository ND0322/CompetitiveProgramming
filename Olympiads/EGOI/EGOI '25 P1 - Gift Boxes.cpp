#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;
/*
consider each i as a left point
find the minimum r such that from [1:i] and [r:n] there are no dupes 
2p?

as new elements are introduced in [1:i], r will strictly increase so 2p
*/


int n, a[MAXN];
int main(){
    cin >> n >> n;

    vector<int> pos(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }

    set<int> s;

    int r = n;
    for(int i = n; i >= 1; i--){
        if(s.find(a[i]) != s.end()) break;
        s.insert(a[i]);
        r = i;
    }

    pair<int,pair<int,int>> ans = {r-1, {0, r-2}};

    s.clear();

    for(int i = 1; i < n; i++){
        if(s.find(a[i]) != s.end()) break;
        s.insert(a[i]);
        r = max(r, pos[a[i]]+1);

        ans = min(ans, {r - i - 1, {i, r-2}});

    }

    cout << ans.second.first << " " << ans.second.second << "\n";


}