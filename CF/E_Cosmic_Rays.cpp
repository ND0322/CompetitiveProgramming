#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, a[MAXN], b[MAXN], st[MAXN<<2], last[MAXN];

/*
we can merge two of the same thing if everything in between gets deleted first
build it greedily over the prefix
when adding a new element it will either merge with the previous thing or not 
probably a monostack?
if it merges we sum the two then take max and for no merge we simply take the max of old max and bi
seg tree query max over the distance between the last occurence of this character
update the seg tee at position of left endpoint with new value
*/

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node] = x;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l,mid, i, x);
    else update(node<<1|1,mid+1,r,i,x);
    st[node] = max(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];
    int mid = (l+r)>>1;
    return max(query(node<<1,l,mid,x,y), query(node<<1|1, mid+1,r,x,y));
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

        int ans = 0;
        for(int i = 1; i <= n; i++){

            //after merging change last 
            
            update(1,1,n,i, a[i]);
            ans = max(ans, a[i]);
            if(!last[b[i]]){
                last[b[i]] = i;
                continue;
            }

            int mx = query(1,1,n, last[b[i]]+1, i-1);

            //some updating here probably
            //maybe lazy update with storing the time of merging 
            if(a[i] < mx || a[last[b[i]]] < mx)
            else{
                //update both with the bonus?
                update(1,1,n,last[b[i]], )
            }

        }

    }
}