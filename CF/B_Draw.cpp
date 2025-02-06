#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    pair<int,int> cur = {0,0};

    int ans = 0;

    while(n--){
        int x,y; cin >> x >> y;

        ans += max(0, min(x,y) - max(cur.first, cur.second)+1);
        cur = {x,y};
        if(x == y){
            cur.first++;
            cur.second++;
        }
    }

    cout << ans << "\n";

    
}