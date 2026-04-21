#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

const int MAXN = 3e5+5;

int n, a[MAXN];





typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ost;

/*
checked against:
https://usaco.org/index.php?page=viewproblem2&cpid=578
https://cses.fi/problemset/task/1735/

each shift we cam do a range +1 on (2, n)
change the sum of ea
split into negtive and positive trees and move them when it becomes positive
amortizes to o(n)


query on values number of (1, ai) with index less than me 

5 4 3 2 1
1 + 2 + 3 + 4

4 3 2 1 5

remove 5
query on the remaining set
query on the prefix
add back the 5
*/

struct Node{
    long long mn, mx, sum, lzAdd, lzSet;
    Node(){};
};

struct segtree{
    Node st[MAXN<<2];

void pushdown(int node, int l, int r, int mid){
    if(st[node].lzSet){
        st[node<<1].lzSet = st[node<<1|1].lzSet = st[node].lzSet;
        st[node<<1].lzAdd = st[node<<1|1].lzAdd = 0;
        st[node<<1].mn = st[node<<1|1].mn = st[node].lzSet;
        st[node<<1].mx = st[node<<1|1].mx = st[node].lzSet;

        if(l != r){
            st[node<<1].sum = st[node].lzSet * (mid-l+1);
            st[node<<1|1].sum = st[node].lzSet * (r-mid);
        }
        
    }

    if(st[node].lzAdd){
        st[node<<1].lzAdd += st[node].lzAdd;
        st[node<<1|1].lzAdd += st[node].lzAdd;
        st[node<<1].mn += st[node].lzAdd;
        st[node<<1|1].mn += st[node].lzAdd;
        st[node<<1].mx += st[node].lzAdd;
        st[node<<1|1].mx += st[node].lzAdd;
        if(l != r){
            st[node<<1].sum += st[node].lzAdd * (mid-l+1);
            st[node<<1|1].sum += st[node].lzAdd * (r-mid);
        }
    }

    st[node].lzAdd = st[node].lzSet = 0;
}

void build(int node, int l, int r){
    if(l == r){
        st[node].mn = a[l];
        st[node].sum = a[l];
        st[node].mx = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l, mid);
    build(node<<1|1,mid+1,r);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void add(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn += v;
        st[node].mx += v;
        st[node].sum += (r-l+1)*v;
        st[node].lzAdd += v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    add(node<<1, l, mid, x, y, v);
    add(node<<1|1, mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

void update(int node, int l, int r, int x, int y, long long v){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].mn = v;
        st[node].mx = v;
        st[node].sum = (r-l+1)*v;
        st[node].lzAdd = 0;
        st[node].lzSet = v;
        return;
    }

    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    update(node<<1,l,mid,x,y,v);
    update(node<<1|1,mid+1,r,x,y,v);
    st[node].mn = min(st[node<<1].mn, st[node<<1|1].mn);
    st[node].mx = max(st[node<<1].mx, st[node<<1|1].mx);
    st[node].sum = st[node<<1].sum + st[node<<1|1].sum;
}

long long qmn(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e18;
    if(x <= l && y >= r) return st[node].mn;
    int mid = (l+r)>>1;
    pushdown(node, l, r, mid);
    return min(qmn(node<<1, l, mid, x,y), qmn(node<<1|1,mid+1,r,x,y));
}

long long qmx(int node, int l, int r, int x, int y){
    if(x > r || y < l) return -1e18;
    if(x <= l && y >= r) return st[node].mx;
    int mid = (l+r)>>1;
    pushdown(node,l, r, mid);
    return max(qmx(node<<1,l,mid,x,y), qmx(node<<1|1,mid+1,r,x,y));
}

long long qsm(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sum;
    int mid = (l+r)>>1;
    pushdown(node,l,r,mid);
    return qsm(node<<1,l,mid,x,y) + qsm(node<<1|1,mid+1,r,x,y);
}
    
};


int main(){

    int tt; cin >> tt;

    while(tt--){

        cin >> n;

        map<int, int> flipN, flipP;

        for(int i = 1; i <= n; i++) cin >>a[i];
        int pos = 0;
        int neg = 0;

        for(int i = 1; i <= n; i++){
            //switches when ai = i
            //or when we rotate to the end 
            //shift == pos - ai or shift == i 

            if(a[i] - i > 0) pos++;
            if(a[i] - i < 0) neg++;

            if(a[i] < i) flipP[pos - a[i]]++;
            //5 4 3 2 1 
            else flipN[i + n - a[i]]++;
        }


        //segtree pos, neg;
		/*
        for(int i = 1; i <= n; i++){
            if(a[i] >= i) pos.update(1,1,n, i,i, a[i] - i);
            if(a[i] < i) neg.update(1,1,n, i,i, i - a[i]);
        }
        */

     
        

        int cnt = 0;
        int sm = 0;

        ost s;
        for(int i = 1; i <= n; i++){
            sm += abs(a[i] - i);
            cnt += i - s.order_of_key(a[i]) - 1;
            s.insert(a[i]);
        }
        
        cout << cnt << "\n";
        
        vector<int> ans;
    for(int i = 0; i < n; i++){
        //int f = pos.qsm(1,1,n, 1, n) + neg.qsm(1,1,n, 1, n);
        
        cout << sm << " " << cnt << "\n";
        //if(2*cnt <= f) ans.push_back(i);
        
        s.erase(s.find_by_order(s.order_of_key(a[i])));
        //number less than ai in suffix
        cnt -= s.order_of_key(a[i]);
        cnt += n - 2 - s.order_of_key(a[i]);
        s.insert(a[i]);
        cout << cnt << "\n";

        //we know for each ai when it switches from positive 
        //we can therefore keep a count of positives and negatives 

        if(flipN[i]) pos -= flipN[i];
        if(flipP[i]) neg -= flipP[i];


        sm += pos - neg;

        if(flipN[i]) neg += flipN[i];
        if(flipP[i]) pos += flipP[i];       
    }
    
    
    }
    
    
	
    

    



   
}



