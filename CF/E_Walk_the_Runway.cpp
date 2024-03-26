#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef bitset<5000> bs;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int m,n; cin >> m >> n;

    vector<ll> costs(n);

    for (auto &i : costs) {
        cin >> i;
    }

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);

    bs init;

    for(int i = 0; i < n; i++){

        init[i] = true;
    }

    vector<bs> can(n,init);

    //Creating Graph
    for(int t= 0; t < m; t++){
        vector<int> r(n);
        for (auto &r : r) {
                    cin >> r;
                }

        sort(ind.begin(), ind.end(), [&](int i, int j) {
            return r[i] < r[j];
        });

        bs last;

        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && r[ind[j]] == r[ind[i]]){

                can[ind[j]] &= last;
                j++;
            }

            while(i < j){
                last[ind[i]] = true;
                i++;
            }
        }
    }

    //dp!

    vector<ll> dp = costs;

    for(auto i:ind){
        for(int j = 0; j < n; j++){
            //for each child

            if(can[i][j]){
                dp[i] = max(dp[i],costs[i] + dp[j]);
            }
        }
    }

    cout << *max_element(dp.begin(),dp.end()) << "\n";
    return 0;
}