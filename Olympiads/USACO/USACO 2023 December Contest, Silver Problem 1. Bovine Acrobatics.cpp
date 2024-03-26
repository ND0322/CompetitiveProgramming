#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

int n, m,k;

pair<int,int> a[MAXN];

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a,a+n);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,m});

    long long ans = 0;

    for(int i = 0; i < n; i++){
        //a[i].first = max(a[i].first, m);
        int cnt = 0;

        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second;
            if(x + k > a[i].first) break;
            pq.pop();

            if(a[i].second >= y){
                cnt += y;
                a[i].second-=y;
            }
            else{
                cnt += a[i].second;

                pq.push({x,y-a[i].second});
                break;
            }
        }

        ans += cnt;
        pq.push({a[i].first, cnt});
    }

    cout << ans << "\n";
}
