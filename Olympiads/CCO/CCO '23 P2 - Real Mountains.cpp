#include <bits/stdc++.h>
#include <iostream>
#include <queue>

#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e6+3;
const int MINV = 500002;


#define int long long

int n, a[MAXN], b[MAXN], st[MAXN<<2], rmq[MAXN<<2], rmq2[MAXN<<2];

map<int,int> bounds;

map<int,vector<int>> ind;

void build(int node, int l, int r){
    if(l == r){
        rmq[node] = a[l];
        rmq2[node] = a[l];
        st[node] = 1;

        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l ,mid);
    build(node<<1|1, mid+1, r);
    rmq[node] = min(rmq[node<<1], rmq[node<<1|1]);
    rmq2[node] = min(rmq2[node<<1], rmq2[node<<1|1]);
    st[node] = st[node<<1] + st[node<<1|1];
}


void update(int node, int l, int r, int i){
    if(l == r){
        rmq2[node] = 1e9;
        st[node] = 0;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l, mid, i);
    else update(node<<1|1, mid+1,r,i);
    rmq2[node] = min(rmq2[node<<1], rmq2[node<<1|1]);
    st[node] = st[node<<1] + st[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node];

    int mid = (l+r)>>1;
    return query(node<<1, l, mid, x, y) + query(node<<1|1, mid+1,r,x,y);
}

int ql(int node, int l, int r, int x, int y, int k){
    if(x > r || y < l || rmq[node] > k) return -1;
    if(l == r) return l;

    int mid = (l+r)>>1;
    int res = ql(node<<1, l, mid, x, y, k);
    return (res != -1 ? res : ql(node<<1|1, mid+1, r, x,y, k));
}
int qr(int node, int l, int r, int x, int y, int k){
    if(x > r || y < l || rmq[node] > k) return -1;
    if(l == r) return l;

    int mid = (l+r)>>1;
    int res = qr(node<<1|1, mid+1, r, x, y, k);
    return (res != -1 ? res : qr(node<<1, l, mid, x, y, k));
}

int qmn2(int node, int l, int r, int x, int y){
    if(x > r || y < l) return 1e9;
    if(x <= l && y >= r) return rmq2[node];

    int mid = (l+r)>>1;
    return min(qmn2(node<<1, l, mid, x, y), qmn2(node<<1|1, mid+1,r,x,y));
}


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    pair<int,int> peak = {-1,-1};

    int pmax = 0;
    set<int> s;

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        peak = max(peak, {a[i], i});
        s.insert(a[i]);

        ind[a[i]].push_back(i);
        pmax = max(pmax, a[i]);

        b[i] = pmax;
    }

    

    int smax = 0;

    for(int i = n; i >= peak.second; i--){
        smax = max(smax, a[i]);
        b[i] = smax;
    }


    for(int i = 1; i <= n; i++) ans = (ans + (((b[i] + a[i]-1) % MOD) * ((b[i] - a[i]) % MOD) * MINV) % MOD) % MOD;
    build(1,1,n);

    //we can just shrink the search space later when stuff reachs b

    int ll = 1;
    int rr = n;

    for(int i : s){
        
        while(ll < n && max(a[ll], i) >= b[ll]) ll++;
        while(rr > 1 && max(a[rr], i) >= b[rr]) rr--;

        if(ll > rr || s.find(i) == prev(s.end())) break;

        for(int j : ind[i]) update(1,1,n, j);
        
        

        int hi = rr;
        int lo = ll;

        int l = ql(1,1,n, ll, rr, i);
        int r = qr(1,1,n, ll,rr, i);       

        if (l == -1 || r == -1) continue;

        int s1 = qmn2(1,1,n, l, n);
        int s2 = qmn2(1,1,n, r, n);
        int p1 = qmn2(1,1,n, 1, l);
        int p2 = qmn2(1,1,n, 1, r);

        int cnt = query(1,1,n, l, r);

        if(l == r) ans = (ans + ((*next(s.find(i)) - i) * (p1 + s2) % MOD) % MOD) % MOD;
        
        else{
            int dif = (*next(s.find(i)) - i) % MOD;
            int ext = ((((((r-l-cnt-1) % MOD * ((*next(s.find(i)) + i - 1) % MOD)) % MOD) * dif) % MOD) + (((*next(s.find(i)) + i - 1) * dif) % MOD * MINV) % MOD) % MOD;

            ans = ((ans + (dif * ((p1 + s2 + min(s1, p2) + 1) % MOD + (2 * (r-l+1 - cnt - 2)) % MOD)) % MOD) % MOD + ext) % MOD;
        }
        
        
        

        
    }
    


    cout << ans << "\n";

}

/*
the question can be handled in three parts:
from 1 to l of peak
from l to r of peak
from r of peak to n

parts 1 and 3 we simply lift each one up to the pmax and smax respectively
part 2 we lift to the peak height

we can split each mountain into searching prefix and suffix

lets say we have a group of equal summed things

obviusly for a chunk we should first raise the left and right respectively
let l1 and r1 be the prefix and suffix max at l
let l2 and r2 be prefix and suffix max at r

it is clear that l1 == l2 and r2 == r2 the array a does not yet equal b

total cost will be 2 * pref + 2 * suf - max(pref, suf)

what is cost for group of length n to raise to min(pref, suf)

((2 * pref + 2 * suf - max(pref, suf)) + 2 * (n-2)) * (delta-1)

where delta = second smallest - smallest 

for n = 1 it is just

(delta - 1) * (pref + suf)


we can maybe exchange argument for sub 2 

notice that it is always optimal to raise the chunk with minimal value
what do we do if there are multiple chunks?
we should just collapse contiguous same value into one element with some math so now we just become a merge operation


lets say we have


5 2 2 2 2 6 7 4 2 2 2 2 6 

denote p1 and s1 as prefix and suffix of group 1
similarly p2 and 2 for group 2

we always need to pay p1 and s2

buy left first:

p1 + s1 + 1 + s2

buy right first

p2 + s2 + 1 + p1 

s2 + p1 + 1 + min(s1, p2)

notice that if we have a third middle segment, the s and p are always at least as bad as the two edges so we should never raise it

we can just look at the leftmost and rightmost occurence of x and disregard intervals (we only need the number of such x)
*/