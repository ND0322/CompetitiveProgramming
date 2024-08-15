#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], x;

bool flag = 1;

vector<int> adj[MAXN];

//bsearch + simulate the stuff upwards 
//keep min a[i] - x

//we need to query the boi above me  - sum a[i]

/*
        1
       / \
      2   3
          |
          4

    1 2
    |
    3 3
    |
    2 5
    |
    5 6
    |
    4 9

*/

int dfs(int node, int par){
    int sub = 2e9;


    for(int child : adj[node]){
        if(child == par) continue;
        sub = min(sub, dfs(child, node));
    }

    if(node != 1){

        if(a[node] + (sub == 2e9 ? 0 : sub) < x) flag = 0;
        if(!flag) return -1;


        sub -= max(0,(x - a[node]));

        int val = 0;
        if(a[node] < x) val = 0;
        else val = a[node] - x; 
       
        //val is current a[i]

        if(val < sub && sub != 2e9){
            int tmp = sub;
            sub -= ((sub+val)/2) - val;
            val = (tmp + val)/2;
            
        }


        return min(val, sub);
    }

    return 0;

    
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            adj[i].clear();
        }
        for(int i = 2; i <= n; i++){
            int p; cin >> p;

            adj[p].push_back(i);
            adj[i].push_back(p);
        }

        int lo = 1; 
        int hi = 1e9;

        int ans = 0;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            x = mid;   
            flag = 1;
            dfs(1,-1);

            if(flag){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }

        cout << ans+a[1] << "\n";




    }
}