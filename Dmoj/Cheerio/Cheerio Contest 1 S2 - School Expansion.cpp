#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#define int long long

using namespace std;

int32_t main(){
    int n,a,b; cin >> n >> a >> b;

    priority_queue<pair<int,pair<int,int>>> pq;

    long long ans = 0;
    pq.push({-(a+b),{1,1}});

    for(int i = 0; i < n; i++){
        ans += -pq.top().first;

        auto [x,y] = pq.top().second;

        pq.pop();

        pq.push({-(x*a + b * (y+1)), {x,y+1}});

        if(y == 1) pq.push({-((x+1) * a + b), {x+1,y}});
        
    }

    cout << ans << "\n";



    /*
     int cx = 1;
    int cy = 0;

    long long ans = 0;

    

    for(int i = 0; i < n; i++){
        long long f = (cx+1) * a + b;
        long long s = cx * a + b * (cy+1);

        cout << cx << " " << cy << "\n";

        cout << f << " " <<s << "\n";

        if(f < s){
            ans += f;
            cx++;
            cy = 1;
        }
        else{
            ans += s;
            cy++;
        }

        
    }

    

    cout << ans << "\n";
    */

   
}