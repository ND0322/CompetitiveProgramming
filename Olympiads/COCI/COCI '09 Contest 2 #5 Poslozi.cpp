#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 15;

int n, m;
map<string,int> par[2];

pair<int,int> swaps[205];

//do the double ended bfs trick like in the random graph question

int main(){
    cin >> n >> m;

    string a = "", b = "";

    for(int i = 1; i <= n; i++){
        char x; cin >> x;
        a += x;
        b += i + '0';
    }

    if(a == b){
        cout << "0\n";
        return 0;
    }

    for(int i = 1; i <= m; i ++) cin >> swaps[i].first >> swaps[i].second;

    
    //switch to strings if this sucks
    queue<pair<string, bool>> q;
    q.push({a, 0});
    par[0][a] = -1;
    q.push({b, 1});
    par[1][b] = -1;

    while(q.size()){
        auto [node, t] = q.front();
        q.pop();

        if(par[!t].find(node) != par[!t].end()){
            //stuff

            vector<int> ans;
            string cur = node;
            while(par[0][cur] != -1){
                int i = par[0][cur];
                swap(cur[swaps[i].first - 1], cur[swaps[i].second-1]);
                ans.push_back(i);
            }

            reverse(ans.begin(), ans.end());

            cur = node;
            while(par[1][cur] != -1){
                int i = par[1][cur];
                swap(cur[swaps[i].first - 1], cur[swaps[i].second-1]);
                ans.push_back(i);
            }

            cout << ans.size() << "\n";

            for(int i : ans) cout << i << "\n";
            return 0;


        }

        for(int i= 1; i <= m; i++){
            string child = node;
            swap(child[swaps[i].first - 1], child[swaps[i].second-1]);
            if(par[t].find(child) == par[t].end()){
                par[t][child] = i;
                q.push({child, t});
            }
        }

        
    }

}