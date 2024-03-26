#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5e5+5;
const int MAXM = 2e6+5;


//if theres a 0, its already good, or there is a negative of another number in the range

//for each a[i] keep a set of positions that match with it

int n, q, a[MAXN], psa[MAXN];

vector<pair<int,int>> blocks[MAXM];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    //closest left and right and check if its contained



    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        a[i] = x;

        psa[i] = (x == 0) + psa[i-1];
    }    

    
    
    
    int i = 1;

    while(i <= n){
            
        
        int tmp = a[i];

        int r = -1;

        int l = i;

        while(i <= n && a[i] == tmp){
            r = i;
            i++;
        }

        blocks[a[l] + 1000000].push_back({l, r});        
    }
    
    vector<pair<int,int>> queries;


    
    while(q--){
        int l, r; cin >> l >> r;

        queries.push_back({l,r});
    }

    sort(queries.begin(), queries.end());
    

    for(auto [l,r] : queries){
        if(psa[r] - psa[l-1] >= 1){
            cout << "YES\n";
            continue;
        }

            

        int lo = 0;
        int hi = blocks[(int)(a[l] + 1000000)].size()-1;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(l >= blocks[(int)(a[l] + 1000000)][mid].first){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

    

        if(ans != -1 && blocks[(int)(a[l] + 1000000)][ans].second >= r){
            cout << "YES\n";
            continue;
        }

    

    }
    

    
    
}


/*
try to solve a quickly
b go with your instinct instead of just sitting there
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/