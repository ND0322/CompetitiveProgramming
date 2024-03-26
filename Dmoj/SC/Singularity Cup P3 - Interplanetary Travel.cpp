#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;



const int MAXN = 1e6+5;

//keep pq for left and right of p
//keep farthest left and right
//keep current cap and update when pq are too far
//use farthest left to calc and update cap

typedef pair<long long, int> pii;

int n, m, p, deg[MAXN],x,y;

long long a[MAXN];



vector<int> adj[MAXN];

priority_queue<pii, vector<pii>, greater<pii>> rq;
priority_queue<pii> lq;

int main(){
    scanf("%d %d %d", &n, &m, &p);
    

    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);

        if(y != p){
            deg[x]++;
            adj[y].push_back(x);
        }

    }

    long long lb = 1e18, rb=0;

    for(int i = 1; i <= n; i++){
        lb = min(lb,a[i]);
        rb = max(rb,a[i]);
        if(i == p) continue;

        if(!deg[i]){
            if(a[i] < a[p]) lq.push({a[i],i});
            else rq.push({a[i],i});

            
        }
    }

    long long l = a[p];
    long long r = a[p];

    long long ans = 0;



    




    while(true){
                
       
        while(!lq.empty() && l-ans <= lq.top().first){

            
            //cout << lq.top() << "\n";
            int tmp = lq.top().second;
            l = min(l,lq.top().first);
            
            
            lq.pop();
            for(int i : adj[tmp]){
                
                deg[i]--;

                if(!deg[i]){
                    //cout << i << "\n";
                    
                    if(a[i] < a[p]) lq.push({a[i],i});
                    else rq.push({a[i],i});
                }
            }

            

            
        }

      

        while(!rq.empty() && r+ans >= rq.top().first){
            r = max(r,rq.top().first);
            int tmp = rq.top().second;
            rq.pop();

            for(int i:adj[tmp]){
                deg[i]--;

                if(!deg[i]){
                    //cout << i << "\n";
                    if(a[i] < a[p]) lq.push({a[i],i});
                    else rq.push({a[i],i});

                    
                }
            }

        }



        if(l <= lb && r >= rb) break;

        long long opt1 = 1e18;
        long long opt2 = 1e18;

        if(lq.size()) opt1 = (l-lq.top().first);
        if(rq.size()) opt2 = (rq.top().first-r);

        ans = max(ans,min(opt1,opt2));


        //cout << opt1 << " " << opt2 << "\n";

        
    }

    
    
    printf("%lld\n", ans);


}