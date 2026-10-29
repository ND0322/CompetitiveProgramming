#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
any size 1 components are bad 

obviously any graph with a coloring has at least 2 colorings 
*/



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;


        vector<int> deg(n+1);
        for(int i = 1; i <= m; i++){
            int x,y; cin >> x >> y;

            deg[x]++;
            deg[y]++;
        }


        int mx = 0;
        int cnt = 0;

        bool flag = 1;
        for(int i = 1; i <= n; i++){
            mx = max(mx, deg[i]);

            cnt += deg[i] == 1;
            if(!deg[i]){
                flag = 0;
                cout << "Brain Melt\n";
                break;
            }
        }

        if(!flag) continue;

        
        if(mx == n-1 && cnt == n-1) cout << "2\n";
        else cout << "Many\n";
    }
}