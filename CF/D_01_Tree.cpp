#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, cnt[MAXN];

vector<int> ind[MAXN];

bool dac(int l, int r, int d){
    if(l >= r) return 1;

    if(cnt[d] >= ind[d].size()) return 0;
    if(ind[d][cnt[d]] >= r) return 0;

    bool ans = 1;

    while(cnt[d] < ind[d].size() && ind[d][cnt[d]] < r){
        ans &= dac(l, ind[d][cnt[d]], d+1);
        l = ind[d][cnt[d]]+1;
        cnt[d]++;
    }

    return ans & dac(l,r,d+1);
}

int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i <= n; i++){
            cnt[i] = 0;
            ind[i].clear();
        }

        int check = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            ind[x].push_back(i);
            if(!x) check++;
        }

        if(check > 1){
            cout << "NO\n";
            continue;
        }

        cout << (dac(0,n,0) ? "YES\n" : "NO\n");
    }
    


}