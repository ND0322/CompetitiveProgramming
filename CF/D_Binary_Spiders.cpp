#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;
const int MAXB = 31;

int n, q, tr[MAXN*MAXB][2], tot = 1, dp[MAXN*MAXB][2], rebuild[MAXN*MAXB][2], k;


void tomax2(int x,int y){}

pair<int,int> a[MAXN];

//shouldve gotten this

void insert(int x, int id){

    
    int u = 1;
    int t;

    if(dp[u][0] <dp[id][1]){
        dp[u][0] = dp[id][1];
        rebuild[u][0] = id;
    }
    



    for(int i = MAXB-1; i >= 0; i--) {
        t = (x>>i)&1;
        if(!tr[u][t]) tr[u][t] = ++tot;
        u = tr[u][t];

        if(dp[u][0] <dp[id][1]){
            dp[u][0] = dp[id][1];
            rebuild[u][0] = id;
        }
    }
}

void query(int x, int id){

    int u = 1;

    for(int i = MAXB-1; i >= 0; i--){
        int t = (x>>i)&1;

        //cout << i << " " << x << " " << id << " " << ((k>>i)&1) << "\n";
        if((k>>i)&1){
            if(!tr[u][t^1])return;
            u = tr[u][t^1];
        }
        else{
            if(tr[u][t^1]){
                if(dp[id][1] < dp[tr[u][t^1]][0]+1){
                    dp[id][1] = dp[tr[u][t^1]][0]+1;
                    rebuild[id][1] = rebuild[tr[u][t^1]][0];
                }
            }

            if(!tr[u][t]) return;
            u = tr[u][t];
        }
    }
    if(dp[id][1] < dp[u][0]+1){
        dp[id][1] = dp[u][0]+1;
        rebuild[id][1] = rebuild[u][0];
    }
}
int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++){
        int x = a[i].first;
        int id = a[i].second;

       
        dp[id][1] = 1;
        rebuild[id][1] = 0;

        query(x,id);
        insert(x, id);

        //cout << id << " " << dp[id][1] << "\n";
    }

    pair<int,int> ans = {0,0};

    
    for(int i = 1; i <= n; i++) ans = max(ans, {dp[i][1], i});

    if(ans.first <= 1){
        cout << "-1\n";
        return 0;
    }

    cout << ans.first << "\n";

    int x = ans.second;
    while(x){
        cout << x << " ";
        x = rebuild[x][1];
    }

    cout << "\n";
}