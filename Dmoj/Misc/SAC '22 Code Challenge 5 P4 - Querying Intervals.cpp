#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,q;

pair<int,int> in[MAXN];

vector<pair<int,int>> ranges;

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> in[i].second >> in[i].first;

    sort(in+1, in+n+1);

    int i = 1;

    while(i <= n){
        pair<int,int> th = {-1, in[i].second};
        int r = in[i].first;
        while(i <= n && r >= in[i].second-1){
            r = in[i].first;
            i++;
        }

        th.first = r;
        ranges.push_back(th);
    }

    while(q--){
        int l, r; cin >> l >> r;

        int lo = 0;
        int hi = ranges.size()-1;

        int ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(l >= ranges[mid].second){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }

        if(ans == -1){
            cout << "N\n";
            continue;
        }

        cout << (ranges[ans].first >= r ? "Y\n" : "N\n");
    }

}