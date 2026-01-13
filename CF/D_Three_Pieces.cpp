#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 15;

int n, a[MAXN][MAXN];

pair<int,int> where[MAXN*MAXN], dp[MAXN][MAXN][MAXN][MAXN][3];

vector<int> ti = {1,1,-1,-1,2,2,-2,-2};
vector<int> tj = {2,-2,2,-2,1,-1,1,-1};



/*
graph 

bfs or dijk

current cell, piece, target cell

n^5 * 3
*/


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];

            where[a[i][j]] = {i,j};
        }
    }


    memset(dp, 0x3f, sizeof(dp));


    dp[where[1].first][where[1].second][where[2].first][where[2].second][0] = {0,0};
    dp[where[1].first][where[1].second][where[2].first][where[2].second][1] = {0,0};
    dp[where[1].first][where[1].second][where[2].first][where[2].second][2] = {0,0};


    priority_queue<pair<pair<int,int>, pair<pair<pair<int,int>,pair<int,int>>, int>>, vector<pair<pair<int,int>, pair<pair<pair<int,int>,pair<int,int>>, int>>>, greater<pair<pair<int,int>, pair<pair<pair<int,int>,pair<int,int>>, int>>>> pq;


    pq.push({{0,0}, {{{where[1].first, where[1].second}, {where[2].first, where[2].second}}, 0}});
    pq.push({{0,0}, {{{where[1].first, where[1].second}, {where[2].first, where[2].second}}, 1}});
    pq.push({{0,0}, {{{where[1].first, where[1].second}, {where[2].first, where[2].second}}, 2}});

    while(pq.size()){
        auto node = pq.top();

        pq.pop();

        pair<int,int> d = node.first;

        auto [x,y] = node.second.first.first;
        auto [tx,ty] = node.second.first.second;
        int p = node.second.second;

        if(p == 0){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    int nx = x + ti[i];
                    int ny = y + tj[j];

                    if(nx < 1 || ny < 1 || nx > n || ny | n) continue;

                    if()
                }
            }
        }

    }

}