#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 3e5+5;

int n, r[MAXN];

struct Node{
    int mn, mx;
} st[MAXN<<2];

/* 
find the leftmost max such that remaining length is at least remaining sub length
keep the leftmost beginning 


this is an easy greedy question im gonna jump
*/

Node comb(Node a, Node b){
    Node ans;

    ans.mn = min(a.mn, b.mn);
    ans.mx = max(a.mx, b.mx);
    return ans;
}

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node].mn = x;
        st[node].mx = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid,i,x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = comb(st[node<<1], st[node<<1|1]);
}

Node query(int node, int l, int r, int x, int y){
    if(x > r || y < l){
        Node dummy;
        dummy.mx = 0;
        dummy.mn = 1e9;
        return dummy;
    }
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return comb(query(node<<1,l,mid,x,y), query(node<<1|1,mid+1,r,x,y));
}



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<set<int>> ind(n+1);
        set<int> s;

        //seg tree or smth where we keep the leftmost index of that ai
        //update all between after a jump
        //binary search over rmq for the min/max thing with length remaining good 👍

        for(int i = 1; i <= n; i++) r[i] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            ind[a[i]].insert(i);
            r[a[i]] = i;
            s.insert(a[i]);
            update(1,1,n,i, 1e9);
        }


        //minimum of maximum indices 

        set<int> suf;

        for(int i = 1; i <= n; i++){
            if(r[i]) suf.insert(r[i]);
        }

        int m = s.size();

        cout << m << "\n";

        for(int i = 1; i <= n; i++){
            if(!ind[i].size()) continue;
            update(1,1,n, i, *ind[i].begin());
        }

        int pos = 0;
        bool p = 0;
        while(m--){

            //cout << "s " << *suf.begin() << "\n";
        
            if(!p){
                //max such that l + m <= n
                int lo = 1;
                int hi = *s.rbegin();
                int ans = -1;

                while(lo <= hi){
                    int mid = (lo+hi)>>1;
                    
                    if(query(1,1,n,mid, *s.rbegin()).mn <= *suf.begin()){
                        lo = mid+1;
                        ans = mid;
                    }
                    else hi = mid-1;
                }
                int balls = query(1,1,n,ans, n).mn;
                update(1,1,n, ans, 1e9);
                ind[ans].clear();
                s.erase(ans);
                suf.erase(r[ans]);

                for(int i = pos; i <= balls; i++){
                    if(ind[a[i]].size()){
                        ind[a[i]].erase(ind[a[i]].begin());
                        if(ind[a[i]].size()) update(1,1,n, a[i], *ind[a[i]].begin());
                        else update(1,1,n, a[i], 1e9);
                    }
                }

                cout << ans << " ";

                pos = balls;
            }

            else{
                //max such that l + m <= n
                int lo = *s.begin();
                int hi = n;
                int ans = -1;

                while(lo <= hi){
                    int mid = (lo+hi)>>1;

                    //cout << mid << " " << query(1,1,n,1, mid).mn << "\n";
                    
                    if(query(1,1,n,*s.begin(), mid).mn <= *suf.begin()){
                        hi = mid-1;
                        ans = mid;
                    }
                    else lo = mid+1;
                }

                int balls = query(1,1,n,1,ans).mn;
                update(1,1,n, ans, 1e9);
                ind[ans].clear();

                for(int i = pos; i <= balls; i++){
                    if(ind[a[i]].size()){
                        ind[a[i]].erase(ind[a[i]].begin());
                        if(ind[a[i]].size()) update(1,1,n, a[i], *ind[a[i]].begin());
                        else update(1,1,n, a[i], 1e9);
                    }
                }

                s.erase(ans);
                suf.erase(r[ans]);

                cout << ans << " ";
                
                pos = balls;
            }

            p ^= 1;
        }

        cout << "\n";


    }
}