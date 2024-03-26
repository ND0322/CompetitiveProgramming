#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAXN = 3e5+5;

int n, a[MAXN];
map<int,set<int>> ind;

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        
        for(int i = 0; i < n; i++){
            cin >> a[i];

            ind[a[i]] = set<int>();
        }

        for(int i = 0; i < n; i++) ind[a[i]].insert(i);

        int ans = -1;

        for(int i = 0; i < n; i++){
            if(ind[a[i]].lower_bound(i+1) == ind[a[i]].end()) continue;
            ans = max(ans,i + n-*ind[a[i]].lower_bound(i+1));
            
        }

        cout << ans << "\n";

    }
}