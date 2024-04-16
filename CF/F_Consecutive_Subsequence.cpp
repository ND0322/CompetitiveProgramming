#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, dp[MAXN], a[MAXN], rebuild[MAXN];
map<int,set<int>> mp;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];

        mp[a[i]].insert(i);
    }


    for(int i = n-1; i >= 1; i--){
        if(mp[a[i]+1].lower_bound(i) != mp[a[i]+1].end()){
            dp[i] = dp[*mp[a[i]+1].lower_bound(i)]+1;
            rebuild[i] = *mp[a[i]+1].lower_bound(i);
        }
        
    }

    
    pair<int,int> ans = {-1,-1};

    for(int i = 1; i <= n; i++) ans = max(ans, {dp[i]+1, i});

    cout << ans.first << "\n";
    int i = ans.second;
    while(i){
        cout << i << " ";
        i = rebuild[i];
    }

    
    cout << "\n";
}