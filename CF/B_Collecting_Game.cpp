#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

int n, ans[MAXN];

bool added[MAXN];

pair<int,int> a[MAXN];


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i].first;
            a[i].second = i;
            added[i] = 0;
        }

        sort(a+1,a+n+1);

        int tot = 0;

        int r = 1;

        for(int i = 1; i <= n; i++){
            if(!added[i]){
                tot += a[i].first;
                added[i] = 1;
            }

            //cout << i << " " << tot << "\n";

            while(r < n && tot >= a[r+1].first){
                r++;
                if(!added[r]){
                    tot += a[r].first;
                    added[r] = 1;
                }
                
                
            }

            ans[a[i].second] = r-1;
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";

        cout << "\n";

       


    }
}