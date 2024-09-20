#include <bits/stdc++.h>
#include <iostream>
#include <set>



using namespace std;

const int MAXN = 5e5+5;
const int MAXM = 205;

int n, q, a[MAXN], ans[MAXN], cnt[MAXN], t[MAXN][MAXM];
vector<pair<pair<int,int>,int>> queries[MAXN];
vector<int> ord;
vector<int> ind[MAXN];

//> sqrt will only have at most sqrt elements that satisfy it 

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    for(int i =1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(cnt[i] > 200) ord.push_back(i);
    }

    for(int i = n; i >= 1; i--) ind[a[i]].push_back(i);
    

    for(int i = 1; i <= q; i++){
        int l,r, k; cin >> l >> r >> k;

        queries[l].push_back({{k,r}, i});
    }


    for(int i = 1; i <= 200; i++){
        memset(cnt, 0, sizeof(cnt));
        int r = 0;

        
        for(int j = 1; j <= n; j++){
            while(r < n && cnt[a[r+1]]+1 != i) cnt[a[++r]]++;
            

            t[j][i] = r+1;
            cnt[a[j]]--;
        }
    }

    for(int i = 1; i <= n; i++){
        for(auto j : queries[i]){
            auto [k,r] = j.first;

            if(k <= 200) ans[j.second] = (t[i][k] <= r ? a[t[i][k]] : -1);
            else{
                pair<int,int> best = {1e9, -1};

                for(int l : ord){
                    if(ind[l].size() < k) continue;
                    best = min(best, {ind[l][ind[l].size() - k], l});
                }

                ans[j.second] = (best.first <= r ? best.second : -1);

            }
        }

        ind[a[i]].pop_back();
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << "\n";




}