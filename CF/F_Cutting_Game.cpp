#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n,q, l[2], r[2], ll[2], rr[2];

vector<pair<int,int>> xs,ys; 
set<pair<int,int>> rem;

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        cin >> r[0] >> r[1];
        l[0] = 1;
        l[1] = 1;

        xs.clear();
        ys.clear();

        for(int i = 1; i <= n; i++){
            int x,y; cin >> x >> y;

            xs.push_back({x,y});
            ys.push_back({y,x});
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        ll[0] = 1;
        ll[1] = 1;
        rr[0] = n;
        rr[1] = n;

        bool flag = 1;
        int score[2] = {0,0};

        while(q--){
            char c; cin >> c;
            int x; cin >> x;

            int cnt = 0;

            if(c == 'U'){
                while(l[0]+x > xs[ll[0]].first && ll[0] <= rr[0]){
                    cnt += rem.find(xs[ll[0]]) == rem.end();
                    rem.insert(xs[ll[0]]);
                    ll[0]++;
                }
                l[0] += x;
            }

            if(c == 'D'){
                while(r[0]-x < xs[rr[0]].first && ll[0] <= rr[0]){
                    cnt += rem.find(xs[rr[0]]) == rem.end();
                    rem.insert(xs[rr[0]]);
                    rr[0]--;
                }
                r[0] -= x;
            }

            if(c == 'L'){
                while(l[1] + x > ys[ll[1]].first && ll[1] <= rr[1]){
                    cnt += rem.find({ys[ll[1]].second, ys[ll[1]].first}) == rem.end();
                    rem.insert({ys[ll[1]].second, ys[ll[1]].first});
                    ll[1]++;
                }

                l[1]+=x;
            }

            if(c == 'R'){
                while(r[1] - x < ys[rr[1]].first && ll[1] <= rr[1]){
                    cnt += rem.find({ys[rr[1]].second, ys[rr[1]].first}) == rem.end();
                    rem.insert({ys[rr[1]].second, ys[rr[1]].first});
                    rr[1]--;
                }

                r[1]-=x;
            }

            score[flag^1] += cnt;
        }

        cout << score[0] << " " << score[1] << "\n";
    }
}