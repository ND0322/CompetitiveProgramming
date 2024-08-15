#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, m, a[MAXN][2];

pair<bool, bool> want[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;
        
        for(int i = 1; i <= n+m+1; i++) cin >> a[i][0];
        for(int i = 1; i <= n+m+1; i++) cin >> a[i][1];

        int cnt[2] = {0,0};

        long long sm = 0;

        int ind = 1e9;

        for(int i = 1; i <= n+m; i++){
            want[i].first = a[i][1] > a[i][0];
            want[i].second = 0;

            if(!want[i].first && cnt[0] < n){
                want[i].second = 1;
                cnt[0]++;
            }
            
            if(want[i].first && cnt[1] < m){
                want[i].second = 1;
                cnt[1]++;
            }

            if(!want[i].second) ind = min(ind,i);

            sm += a[i][want[i].first ^ (!want[i].second)];

        }

        //cout << sm << "\n";

        long long ans = 0;

        for(int i = 1; i <= n+m; i++){
            long long k = 0;
            if(ind != 1e9 && i < ind){
                k = sm - a[i][want[i].first ^ (!want[i].second)];

                bool saved = want[i].first ^ (!want[i].second);

                if(want[ind].first == saved){
                    k += a[ind][saved];
                    k -= a[ind][!saved];
                    k += a[n+m+1][!saved];

                }
                else k += a[n+m+1][saved];

            }
            else{
                k = sm - a[i][want[i].first ^ (!want[i].second)];
                k += a[n+m+1][want[i].first ^ (!want[i].second)];
            }

            cout << k << " ";

        }

        cout << sm << "\n";
   
    }
}
