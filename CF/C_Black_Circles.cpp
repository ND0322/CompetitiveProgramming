#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//greedy check for time and overlap 

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<pair<long long,long long>> circ(n);

        for(int i= 0; i < n; i++) cin >> circ[i].first >> circ[i].second;
        long long a,b,c,d; cin >> a >> b >> c >> d;

        long long dist = (a-c) * (a-c) + (b-d) * (b-d);
        long long close = 9e18;

        for(int i = 0; i < n; i++) close = min(close , (circ[i].first-c) * (circ[i].first-c) + (circ[i].second-d) * (circ[i].second-d));
        
        //cout << dist << " " << close << "\n";

        cout << (dist < close ? "YES\n" : "NO\n"); 
    }
}