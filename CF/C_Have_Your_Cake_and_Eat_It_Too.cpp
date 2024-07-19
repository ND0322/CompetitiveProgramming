#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

//greedy and cycle through permutation order

const int MAXN = 2e5+5;

int n, a[MAXN][3], tot;

vector<int> ord = {0,1,2};

bool can(){
    int i = 1;
    int sm = 0;
    for(; i <= n; i++){
        sm += a[i][ord[0]];
        if(sm >= ceil(tot/3.0)) break;
    }
    if(sm < ceil(tot/3.0)) return 0;

    i++;
 
    sm = 0;
    for(; i <= n; i++){
        sm += a[i][ord[1]];
        if(sm >= ceil(tot/3.0)) break;
    }
    if(sm < ceil(tot/3.0)) return 0;

    i++;
    sm = 0;
    for(; i <= n; i++) sm += a[i][ord[2]];
    
    if(sm < ceil(tot/3.0)) return 0;

    return 1;
}


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        ord = {0,1,2};
        tot = 0;

        for(int i = 1; i <= n; i++) cin >> a[i][0];
        for(int i = 1; i <= n; i++) cin >> a[i][1];
        for(int i = 1; i <= n; i++) cin >> a[i][2];

        for(int i = 1; i <= n; i++) tot += a[i][0];

        bool flag = 0;
        do{
            if(can()){
                //print stuff
                int i = 1;

                vector<pair<int,int>> ans(3);

                ans[ord[0]].first = i;
                int sm = 0;
                for(; i <= n; i++){
                    sm += a[i][ord[0]];
                    if(sm >= ceil(tot/3.0)) break;
                }
                ans[ord[0]].second = i;
                
                i++;

                ans[ord[1]].first = i;
                
                
                sm = 0;
                for(; i <= n; i++){
                    sm += a[i][ord[1]];
                    if(sm >= ceil(tot/3.0)) break;
                }

                ans[ord[1]].second = i;

                i++;
                ans[ord[2]].first = i;

                sm = 0;
                for(; i <= n; i++) sm += a[i][ord[2]];


                ans[ord[2]].second = i-1;

                cout << ans[0].first << " " << ans[0].second << " " << ans[1].first << " " << ans[1].second << " " << ans[2].first << " " << ans[2].second << "\n";

                
                flag = 1;
                break;
            }
        }
        while(next_permutation(ord.begin(), ord.end()));

        if(!flag) cout << "-1\n";
    }
}