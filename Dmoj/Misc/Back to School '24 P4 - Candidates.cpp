#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 3e5+5;

int n, k, ord[MAXN], cnt[MAXN];


set<int> has[MAXN];
//bad colors for each index 

vector<int> a[MAXN];

/*
add them in a way so that no i is fkd over by something in the next array
for each color maintain a how many pairs of adjacent elements are inverted so a[i+1] > a[i]
we can add a certain color only if all inverted pairs are not equal in the last iteration
*/

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> ord[i];
    for(int i = 1; i <= n; i++){
        a[i].push_back(-1);
        for(int j = 1; j <= k; j++){
            int x; cin >> x;

            a[i].push_back(x);
        }
    }

    vector<vector<pair<int,int>>> colors(k+1, vector<pair<int,int>>(1, {-1,-1}));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            colors[j].push_back({a[ord[i]][j], ord[i]});
        }
    }

    for(int i = 1; i <= k; i++){
        for(int j = 1; j < n; j++){
            if(colors[i][j].first < colors[i][j+1].first){
                has[j].insert(i);
                cnt[i]++;
            }
        }        
    }


    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    set<int> inds;

    for(int i = 1; i <= n; i++) inds.insert(i);
    for(int i = 1; i <= k; i++){
        if(!cnt[i]) pq.push(i);

    }

    while(pq.size()){
        int id = pq.top();
        
        pq.pop();

        ans.push_back(id);

        set<int> nxt;
        for(int j : inds){
            if(colors[id][j].first > colors[id][j+1].first) nxt.insert(j);
        }
            
        for(int i : nxt){
            inds.erase(i);

            for(int j : has[i]){
                cnt[j]--;
                if(!cnt[j]) pq.push(j);
            }
        }
    }

    if(ans.size() != k){
        cout << "-1\n";
        return 0;
    }

    for(int i : ans) cout << i << " ";
    cout << "\n";



}
