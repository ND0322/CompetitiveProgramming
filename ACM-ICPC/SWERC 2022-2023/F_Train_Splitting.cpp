#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;

    vector<pair<int,int>> edges;
    vector<int> deg(n+1);

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        edges.push_back({x,y});

        deg[x]++;
        deg[y]++;
    }

    if(m != n * (n-1) / 2){
        int ind = 0;
        for(int i = 1; i <= n; i++){
            if(deg[i] < n-1){
                ind = i;
                break;
            }
        }

        cout << "2\n";

        for(int i = 0; i < m; i++){
            if(edges[i].first == ind || edges[i].second == ind) cout << "1 ";
            else cout << "2 ";
        }
    }
    else{
        cout << "3\n";

        bool flag = 1;

        for(int i = 0; i < m; i++){
            if(flag && (edges[i].first == 1 || edges[i].second == 1)){
                flag = 0;
                cout << "1 ";
                continue;
            }

            if(edges[i].first == 1 || edges[i].second == 1) cout << "2 ";
            else cout << "3 ";
        }
    }

    cout << "\n";

    

}

int main(){
    int tt; cin >> tt;

    while(tt--){
        //k = 2

        solve();
        


    }
}