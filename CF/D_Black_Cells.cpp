#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;


//optimize number of pickups
//save 2 by going longer on the last one 
//add k to cost already
//now depends on how much we move between things and how many pickups
//say for example
//1,1 -> 4,10
//for k = 1
//doing it in first would cost 3
//doing it second would cost 5
//dont worry about that case 
//try all right end points and greedy it


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> a(n+1), b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        int i = 1;

        vector<pair<int,int>> chunks;

        while(i <= n){
            int l = a[i];
            while(i < n && b[i] >= a[i+1]) i++;
            
            chunks.push_back({l, b[i]});
            
            i++;
        }

        
        n = chunks.size();

        long long ans = 1e9;
        long long cur = 0;

        long long sm = 0;


        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++){

            long long tmp = chunks[i].second - chunks[i].first+1;

            if(sm < k){

                if(sm + tmp > k){
                    tmp -= k-sm;
                    sm = k;
                }
                else{
                    sm += tmp;
                    tmp = 0;
                }
                cur += 2;
            }

            cout << sm << " " << cur << " " << tmp << "\n";

            if(sm >= k){
                while(pq.size() && tmp > pq.top()){
                    tmp -= pq.top();
                    pq.pop();
                    cur -= 2;
                }
            }


            

            pq.push(chunks[i].second - chunks[i].first+1);

            if(sm >= k) ans = min(ans, chunks[i].first + cur);
        }

        cout << ans << "\n";

    
    }
}