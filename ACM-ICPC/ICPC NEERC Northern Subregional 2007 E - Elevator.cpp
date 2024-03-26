#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

const int MAXN = 1e5+5;

int a,b,c;

long long h, distances[MAXN];

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;


int main(){
    cin >> h;

    h--;

    memset(distances, 0x3f, sizeof(distances));

    cin >> a >> b >> c;

    distances[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){
        int node = pq.top().second;
        long long d = pq.top().first;

        pq.pop();
        if(d != distances[node]) continue;

        int child = (node+b)%a;
        if(distances[child] > d + b){
            distances[child] = d + b;
            pq.push({d+b, child});
        }
        child = (node+c)%a;
        if(distances[child] > d + c){
            distances[child] = d + c;
            pq.push({d+c, child});
        }

    }

    long long ans = 0;

    for(int i = 0; i < a; i++){
        if(distances[i] <= h) ans += (h-distances[i]) / a + 1;
    }

    cout << ans << "\n";
}