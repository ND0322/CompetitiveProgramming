#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,m,b[MAXN],dp[1<<20],rebuild[1<<20],nxt[MAXN][20];
pair<int,int> a[MAXN];
vector<int> ans[20];

int calcNxt(int i, int k){
    int x = 1;
    //assume we use x ppl on the project

    while(i + x <= n && a[i+x-1].first * x < b[k]) x = (b[k] + a[i+x-1].first - 1) / a[i+x-1].first;
    return x;
}


int main(){
    cin >> n >> m;

    fill(rebuild,rebuild+(1<<m)+1,-1);
    fill(dp,dp+(1<<m)+1,n+1);

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        a[i] = {x,i};
    }
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a,a+n);
    reverse(a,a+n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            nxt[i][j] = min(n+1,calcNxt(i,j));
        }
    }

    dp[0] = 0;

    for(int i = 1; i < (1<<m); i++){
        for(int j = 0; j < m; j++){

             //find a mask that lead to cur
            if(i&(1<<j)){
               
                //calc best
                int best = nxt[dp[i^(1<<j)]][j];

                if(dp[i^(1<<j)] + best < dp[i]){
                    dp[i] = dp[i^(1<<j)] + best;
                    rebuild[i] = j;

                    //cout << true << "\n";
                }
            }
        }
    }


    if(rebuild[(1<<m)-1] == -1){
        cout << "NO\n";
        return 0;
    }

    

    int mask = (1<<m)-1;
    while(mask){
        int temp = mask;

        
    
        mask ^= 1 << rebuild[mask];
        //string s = bitset<20>(mask).to_string();
        //cout << s << "\n";
       
        
        //cout << rebuild[temp] << " ";

        for(int i = dp[mask]; i < dp[temp]; i++){
            ans[rebuild[temp]].push_back(i);

            //cout << i << " ";
            
        }

        //cout << "\n";

        //dfs(mask);
    }

    
    for(int i = 0; i < m; i++){
        if(!ans[i].size()){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    for(int i = 0; i < m; i++){
        cout << ans[i].size();

        cout << " ";

        for(int j : ans[i]) cout << a[j].second+1 << " ";
        cout << "\n";
    }



    


}
