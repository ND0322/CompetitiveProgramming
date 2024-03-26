#include <bits/stdc++.h>
#include <iostream>
#include <deque>

using namespace std;

const int MAXN = 2e6+5;

int out, n, k, dist[MAXN][2];

bool bad[MAXN];


/*
transitioning to all next heights is too damn slow for going down
add extra nodes to transition in o(1)
*/

int main(){
    cin >> out >> k >> n;

    for(int i = 1; i <= n; i++){
        int x,y; cin >> x >> y;
        for(int j = x; j <= y; j++) bad[j] = 1;
    }

    for(int i = 0; i <= out; i++) cout << bad[i] << " ";
    cout << "\n";

  

    memset(dist, 0x3f, sizeof(dist));

    dist[0][0] = 0;


    deque<pair<int,pair<int,bool>>> dq;

    dq.push_front({0,{0,0}});

    while(dq.size()){
        int node = dq.front().first;
        int d = dq.front().second.first;
        bool t = dq.front().second.second;

        cout << node << " " << t << " " << d << "\n";

        dq.pop_front();

        if(!t){
            //convert to other type
            if(dist[node][1] > d + 1){
                dist[node][1] = d + 1;
                dq.push_back({node, {d+1, 1}});
            }


            if(node+k <= 2*out && !bad[node+k] && dist[node+k][0] > d + 1){
                dist[node+k][0] = d + 1;
                dq.push_back({node+k, {d+1, 0}});
            }
        }
        else{
            //keep going

            if(node && dist[node-1][1] > d){
                dist[node-1][1] = d;
                dq.push_front({node-1, {d, 1}});
            }

            if(!bad[node] && dist[node][0] > d){
                dist[node][0] = d;
                dq.push_front({node, {d,0}});
            }
        }
    }

}