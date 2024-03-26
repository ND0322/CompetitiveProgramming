#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int INF = 1e9;

int n,k,a[MAXN],parents[MAXN],s[MAXN],ans[MAXN], st[MAXN<<2];

bool used[MAXN];


int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }

    return x;
}

void uni(int x,int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(x>y) swap(x,y);

    parents[x] = y;
    s[y] += s[x];
    s[x] = s[y];
}

void build(int node, int l = 1, int r = n){
    if(l == r) st[node] = 1;
    else{
        int mid = (l+r)>>1;

        build(node<<1,l,mid);
        build(node<<1|1,mid+1,r);
        st[node] = min(st[node<<1],st[node<<1|1]);
    }
}

void update(int node, int i, int x, int l = 1, int r = n){
    if(l == r) st[node] = x;
    else{
        int mid = (l+r)>>1;
        if(i <= mid) update(node<<1,i,x,l,mid);
        else update(node<<1|1,i,x,mid+1,r);
        st[node] = min(st[node<<1],st[node<<1|1]);
    }
}

int query(int node, int x, int l = 1, int r = n){
    if(l == r) return l;

    int mid = (l+r)>>1;

    if(st[node<<1] <= x) return query(node<<1,x,l,mid);
    else if(st[node<<1|1] <= x) return query(node<<1|1,x, mid + 1, r);
    else return INF;
}

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        parents[i] = i;
        s[i] = 1;
    }

    int last = 0;
    build(1);
    

    for(int i = 1; i <= n; i++){


        //query instead of looping 👍
       
        int j = query(1,k-s[find(a[i])]);

        if(j > find(a[i])) ans[i] = find(a[i]);
        else{
            uni(a[i],j);
            ans[i] = j;
            update(1,find(a[i]),s[find(a[i])]);
        }

        update(1,ans[i],INF);
        

        
        
    }

    for(int i = 1; i <= n-1; i++) cout << ans[i] << " ";
    cout << ans[n] << "\n";

    
}
