#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 2e5+5;

//each turn we find our biggest and try to take their biggest too

//find a faster way to find elements for hard version

int n, a[MAXN][2];

bool used[MAXN];



int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i][0];
        for(int i =0; i < n; i++) cin >> a[i][1];

        //sort by a+b not a-b
        //oopsie doopsie

        vector<pair<int,int>> c;

        for(int i = 0; i < n; i++){
            c.push_back({a[i][0] + a[i][1], i});
        }

        sort(c.begin(), c.end());

        bool turn = 0;
    
        long long ans = 0;

        for(int i = n-1; i >= 0; i--){
            if(!turn) ans += a[c[i].second][0]-1;
            else ans -= a[c[i].second][1]-1;
            turn^=1;
        }

        cout << ans << "\n";
       





    }
}