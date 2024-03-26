#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>



using namespace std;



//sweepline
//events are entering left bound of rectangle and leaving right bound


typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> line;


const int MAXN = 1005;

int n, k, tint[MAXN<<1];

map<int, int> coord;
vector<line> events;

set<int> ys;

int main(){

    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;


    for(int i = 0; i < n; i++){
        int xl, yt, xr, yb, t; cin >> xl >> yt >> xr >> yb >> t;

        //entry
        events.push_back({{xl,yt}, {yb, t}});

        //exit

        events.push_back({{xr,yt},{yb, -t}});

        ys.insert(yt);
        ys.insert(yb);
    }

    sort(events.begin(), events.end());

    vector<int> y;

    for(int i:ys) y.push_back(i);
    for(int i = 0; i < y.size(); i++) coord[y[i]] = i;

    //for(int i:y) cout << i << " ";
    //cout << "\n";

    long long ans = 0;
   
    for(int i = 0; i < events.size(); i++){
        for(int j = 0; j < y.size(); j++){

            
            if(tint[coord[y[j]]] >= k) ans += (y[j+1] - y[j]) * (events[i].first.first - events[i-1].first.first);
        }

        //update tint

        for(int j = coord[events[i].first.second]; j < coord[events[i].second.first]; j++) tint[j] += events[i].second.second;

        
    }

    cout << ans << "\n";
   


}