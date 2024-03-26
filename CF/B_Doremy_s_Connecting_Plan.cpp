#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#define int long long


using namespace std;

typedef pair<int,int> pii;

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, c; cin >> n >> c;

        vector<int> a(n+1);
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i = 1; i <= n; i++){
            cin >> a[i];

            

            if(i > 1)pq.push({i*c - a[i], a[i]});
        }

         

        bool flag = 1;

        while(!pq.empty()){
            //cout << pq.top().first << " " << pq.top().second << "\n";
            if(a[1] >= pq.top().first) a[1] += pq.top().second;
            else{
                cout << "NO\n";
                flag = 0;
                break;
            }
            pq.pop();

            
        }

        if(flag) cout << "YES\n";
    }

    


}