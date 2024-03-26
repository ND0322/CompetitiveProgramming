#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

#define int long long

const int MAXN = 1e4+5;

int n,m,k;

//calc for each possible location range

int32_t main(){
    cin >> n >> m >> k;


    int last = -1;

    vector<pair<int,int>> pos = {{0,0}};



    for(int i = 0; i < m; i++){
        int l, r, t; cin >> l >> r >> t;

        stack<pair<int,int>> tmp;

        for(auto [x,y] : pos){
            int ll = max(0LL, x - k * (t - last));
            int rr = min(n, y + k * (t-last));


            //cout << x << " " << y << " " << ll << " " << rr << "\n";

            

            while(tmp.size() && tmp.top().second >= ll){
                ll = min(ll, tmp.top().first);
                tmp.pop();
            }

            if(r < ll || l > rr){
                tmp.push({ll,rr});
                continue;
            }
            
            if(ll < l) tmp.push({ll,l-1});
            if(rr > r) tmp.push({r+1,rr});
        }

        pos.clear();

        while(tmp.size()){
            pos.push_back({tmp.top().first, tmp.top().second});
            //cout << tmp.top().first<< " " << tmp.top().second << "\n"; 
            tmp.pop();
        }

        reverse(pos.begin(), pos.end());

        last = t;


    }


    cout << (pos.size() ? "YES\n" : "NO\n");
    //for(auto [l,r] : pos) cout << l << " " << r << "\n";
}