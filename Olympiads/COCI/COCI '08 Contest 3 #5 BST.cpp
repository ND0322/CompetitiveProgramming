#include <bits/stdc++.h> 
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 3e5+5;

int n;

map<int,int> depth;


//i over complicated it
//maintain depths with a map

int main(){
    cin >> n;

    int x; cin >> x;

    long long ans = 0;
    depth[x] = 0;
    cout << "0\n";

    for(int i = 2; i <= n; i++){
        cin >> x;

        auto it = depth.lower_bound(x);
        auto b = it;

        if(it == depth.begin()){
            depth[x] = (*it).second+1;
            ans += depth[x];
            cout << ans << "\n";
            continue;
        }
        b--;

        if(it == depth.end()){
            depth[x] = (*b).second+1;
            ans += depth[x];
            cout << ans << "\n";
            continue;
        }

        depth[x] = max((*it).second, (*b).second)+1;
        ans += depth[x];

        cout << ans << "\n";        
    }

    
    

}