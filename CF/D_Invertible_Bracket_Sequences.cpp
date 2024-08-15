#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN =  2e5+5;


//psa has to be positive or 0 for all indices
//psa[l-1] - (psa[i] - psa[l-1]) >= 0
//psa[l-1] * 2 >= psa[i]
//psa[l-1] = psa[r]


int n, psa[MAXN], st[MAXN<<2];

map<int,vector<int>> mp;


void build(int node, int l, int r){
    if(l == r){
        st[node] = psa[l];
        return;
    }

    int mid = (l+r)>>1;

    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    st[node] = max(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return max(query(node<<1,l,mid, x, y), query(node<<1|1,mid+1,r,x,y));
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;


        mp.clear();

        n = s.size();

        for(int i = 0; i < n; i++) psa[i+1] = pow(-1, !(s[i] == '(')) + psa[i];

        for(int i = 1; i <= n; i++) mp[psa[i]].push_back(i);

        //for(int i = 1; i <= n; i++) cout << psa[i] << " ";
        //cout << "\n";

        build(1,1,n);

        long long ans = 0;

        for(auto i : mp){

            vector<int> a = i.second;


            //2p here
            int r = 0;
            for(int j = 0; j < a.size()-1; j++){
                while(r < a.size() && query(1,1,n,a[j]+1, a[r]) <= 2*i.first) r++;
                //cout << a[j] << " " << a[r] << "\n";

                ans += r - j - 1;
            
            }
        }

        cout << ans << "\n";



    }
}