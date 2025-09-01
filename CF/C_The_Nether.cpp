#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
find the longest chain in dag

given that we can query each node at most twice
in each query we are given longest path that goes through those nodes 

use n queries to find length of longest path and starting node 

lets say we start at node u

we can only jump to nodes v that are path length k-1

lets start the second n queries at node u and incrementally query k-1

once one increases the path length it must be the next thing
*/



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> l(n+1);

        vector<vector<int>> bac(n+1, vector<int>());


        for(int i = 1; i <= n; i++){
            cout << "? " << i << " " << n << " ";

            for(int j = 1; j <= n; j++) cout << j << " ";
            cout << "\n";

            cin >> l[i];

            bac[l[i]].push_back(i);
        }

        int u = -1;
        for(int i = n; i >= 1; i--){
            if(bac[i].size()){
                u = *bac[i].begin();
                break;
            }
        }


        vector<int> ans = {u};


        while(ans.size() < l[u]){
            int nxt = l[*ans.rbegin()]-1;

            for(int i : bac[nxt]){
                cout << "? " << u << " " << (int)ans.size() + 1 << " ";

                for(int j : ans) cout << j << " ";

                cout << i << "\n";

                int x; cin >> x;

                if(x > ans.size()){
                    ans.push_back(i);
                    break;
                }
            }
        }


        cout << "! " << ans.size() << " ";

        for(int i : ans) cout << i << " ";

        cout << "\n";
    }   
}