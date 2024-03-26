#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1<<21;

int n, m, distances[MAXN], a[MAXN];

bool visited[MAXN];

queue<int> q;

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
        q.push(x);
        visited[x] = 1;
    }

    while(!q.empty()){
        int node = q.front();

        q.pop();

        for(int i = 0; i <= m; i++){
            if(!visited[node^(1<<i)]){
                visited[node^(1<<i)] = 1;
                distances[node^(1<<i)] = distances[node]+1;
                q.push(node^(1<<i));
            }
        }
    }

    for(int i = 0; i < n; i++){
        int tmp = (1<<(m+1))-1;

        cout << m-distances[tmp^a[i]]+1 << "\n";
    }



}