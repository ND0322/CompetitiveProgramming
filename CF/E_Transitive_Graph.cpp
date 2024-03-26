#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2e5+5;


int n,m, a[MAXN], sz[MAXN], comp[MAXN], low[MAXN], disc[MAXN], t, cnt;

long long sum[MAXN];
bool start[MAXN], in[MAXN], used[MAXN];

vector<int> adj[MAXN], adjScc[MAXN], order;

stack<int> st;

pair<int,long long> dp[MAXN];

void tarjans(int node){
    low[node] = disc[node] = t++;
    in[node] = 1;

    st.push(node);

    for(int child:adj[node]){
        if(!disc[child]){
            tarjans(child);
            
            low[node] = min(low[node], low[child]);
        }
        else if(in[child]){
            low[node] = min(low[node], disc[child]);
        }
    }

    if(low[node] == disc[node]){
        while(st.top() != node){
            sz[cnt]++;
            sum[cnt] += a[st.top()];
            comp[st.top()] = cnt;
            in[st.top()] = 0;
            st.pop();
        }
        sz[cnt]++;
        sum[cnt] += a[node];
        comp[node] = cnt;
        in[node] = 0;
        st.pop();
        cnt++;
    }   
}


void dfs(int node){

    if(used[node]) return;
    used[node] = 1;

    dp[node] = {0,0};
    
    for(int child:adjScc[node]){
        if(!used[child]) dfs(child);

        if(dp[child].first > dp[node].first){
            dp[node].first = dp[child].first;
            dp[node].second = dp[child].second;
        }
        else if(dp[child].first == dp[node].first) dp[node].second = min(dp[node].second, dp[child].second);
    }

    dp[node].first += sz[node];
    dp[node].second += sum[node];
}



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 0; i <= n; i++){
            sz[i] = 0;
            sum[i] = 0;
            low[i] = 0;
            disc[i] = 0;
            start[i] = 1;
            used[i] = 0;
            in[i] = 0;
            dp[i] = {0,0};
            adj[i].clear();
            adjScc[i].clear();
            comp[i] = 0;
        }
        cnt = 0;
        t = 0;
        order.clear();

        while(!st.empty()) st.pop();

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 0; i < m; i++){
            int x,y; cin >> x >> y;

            adj[x].push_back(y);
        }

        for(int i = 1; i <= n; i++) if(!disc[i]) tarjans(i);

        for(int i = 1; i <= n; i++){
            for(int child:adj[i]){
                if(comp[i] == comp[child]) continue;

                adjScc[comp[i]].push_back(comp[child]);
                start[comp[child]] = false;
            }
        }

        pair<int,long long> ans = {0,0};

        for(int i = 0; i < cnt; i++){
            dfs(i);

            //cout << dp[i].first << " " << dp[i].second << "\n";

            if(dp[i].first > ans.first){
                ans.first = dp[i].first;
                ans.second = dp[i].second;
            }
            else if(dp[i].first == ans.first) ans.second = min(ans.second, dp[i].second);
        }

        cout << ans.first << " " << ans.second << "\n";


    }
}