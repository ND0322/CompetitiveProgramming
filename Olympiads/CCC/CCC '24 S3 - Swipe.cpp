#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, a[MAXN], b[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    int i = 1;

    vector<int> sub;

    while(i <= n){
        int x = b[i];

        while(i <= n && b[i] == x) i++;
        sub.push_back(x);
    }

    i = 1;

    for(int j : sub){
        while(i <= n){
            if(a[i] == j) break;
            i++;
        }

        if(i > n){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    int j = 1;
    vector<pair<int,int>> cache;
    vector<pair<char, pair<int,int>>> ans;

    for(int i = 1; i <= n; i++){
        if(a[i] != b[j]) continue;
        int ll = j;
        while(j <= i && b[j] == a[i]) j++;

        if(ll != i && i > ll){
            //clear cache
            reverse(cache.begin(), cache.end());
            for(auto [l,r] : cache) ans.push_back({'R', {l,r}});
            cache.clear();
            //add the new command
            ans.push_back({'L', {ll,i}});
        }
        while(j <= n && b[j] == a[i]) j++;
        if(i != j-1 && j > i) cache.push_back({i,j-1});
    }

    reverse(cache.begin(), cache.end());
    for(auto [l,r] : cache) ans.push_back({'R', {l,r}});
    cout << ans.size() << "\n";
    for(auto q : ans) cout << q.first << " " << q.second.first-1 << " " << q.second.second-1 << "\n";
}