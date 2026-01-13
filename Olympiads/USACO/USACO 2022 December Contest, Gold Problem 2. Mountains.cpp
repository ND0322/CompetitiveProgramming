#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2005;

int n, a[MAXN], m;

set<pair<int,int>> s[MAXN];

/*
from each i we can only see prefix maxes
keep a monotonic set of prefix maxes 

a[j] / j > a[i] / i
a[j] * i > a[i] * j
*/

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(s[i].empty() || (*s[i].rbegin()).first * (a[j] - a[i]) >= (j - i) * (*s[i].rbegin()).second) s[i].insert({j-i, a[j] - a[i]});
            
        }
    }


    cin >> m;

    while(m--){
        int i,x; cin >> i >> x;

        a[i] += x;

        //remove all things that are now shorter than i

        for(int j = 1; j < i; j++){
            auto it = s[j].lower_bound({i - j, -1e9});
            while(it != s[j].end() && (*it).first * (a[i] - a[j]) > (*it).second * (i - j)) it = s[j].erase(it);
            
            if(it == s[j].begin()) s[j].insert({i - j, a[i] - a[j]});
            else{
                it--;
                if((a[i] - a[j]) * (*it).first >= (*it).second * (i - j))  s[j].insert({i - j, a[i] - a[j]});
            }
    
           
        }

        //recalculate starting from i
        s[i].clear();
        for(int j = i+1; j <= n; j++){
            if(s[i].empty() || (*s[i].rbegin()).first * (a[j] - a[i]) >= (j - i) * (*s[i].rbegin()).second) s[i].insert({j-i, a[j] - a[i]});
            
        }

        int ans = 0;
        for(int j = 1; j <= n; j++) ans += s[j].size();

        cout << ans << "\n";
    }

}