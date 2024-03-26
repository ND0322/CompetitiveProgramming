#include <bits/stdc++.h>
#include <iostream>

using namespace std;



const int MAXN = 1e5+5;

long long  N, n, start, d, tmp[MAXN],  b[MAXN], stp[MAXN<<2], stc[MAXN<<2], ans;

int lo, hi;


//first is pos
//second is cost

vector<long long> a; 

void updatep(int node, int l, int r, int i, int val){
    if(l == r){
        stp[node] += val;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) updatep(node<<1, l, mid, i, val);
    else updatep(node<<1|1, mid+1, r, i, val);
    stp[node] = stp[node<<1] + stp[node<<1|1];
}

void updatec(int node, int l, int r, int i, long long val){
    if(l == r){
        stc[node] += val;
        return;
    }

    int mid = (l+r)>>1;

    if(i <= mid) updatec(node<<1,l,mid,i,val);
    else updatec(node<<1|1, mid+1, r, i, val);
    stc[node] = stc[node<<1] + stc[node<<1|1];
}

void update(int l, int r){
    while(l < lo){
        updatep(1, 1, n, b[lo-1], 1);
        updatec(1, 1, n, b[lo-1], tmp[lo-1]);
        lo--;
    }

    while(l > lo){
        updatep(1, 1, n, b[lo], -1);
        updatec(1, 1, n, b[lo], -tmp[lo]);
        lo++;
    }

    while(r < hi){
        updatep(1, 1, n, b[hi], -1);
        updatec(1, 1, n, b[hi], -tmp[hi]);
        hi--;
    }

    while(r > hi){
        updatep(1, 1, n, b[hi+1], 1);
        updatec(1, 1, n, b[hi+1], tmp[hi+1]);
        hi++;
    }
}

//the query is weird so recursive seg
long long query(int node, int l, int r, int i){
    if(l == r){
        long long c = stc[node];

        //im fkn bald
        if(stp[node] > i) c -= a[l-1] * (long long)(stp[node] - i);
        return c;
    }

    int mid = (l+r)>>1;

    if(stp[node<<1|1] >= i) return query(node<<1|1, mid+1, r, i);
    return stc[node<<1|1] + query(node<<1, l,mid, i - stp[node<<1|1]);
}


void dac(int l, int r, int p1, int p2){
    if(l > r) return;

    int mid = (l+r)>>1;

    int best = -1;
    long long res = -1;

    for(int i = p2; i >= p1; i--){
        update(mid,i);

        long long dist = min(i-start, start - mid) + i - mid;
        if(dist > d) continue;

        long long c = query(1,1,n,d-dist);
        if(c > res){
            res = c;
            best = i;
        }
    }

    ans = max(ans,res);

    if(best == -1){
        dac(mid+1, r, p1, p2);
        return;
    }

    dac(l,mid-1, p1, best);
    dac(mid+1,r,best,p2);


}

int main(){
    cin >> N >> start >> d;

    start++;

    for(int i = 1; i <= N; i++){
        cin >> tmp[i];
        a.push_back(tmp[i]);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end() ), a.end());

    //for(int i : a) cout << i << "\n";

    n = a.size();

    lo = 1;
    hi = N;

    for(int i = 1; i <= N; i++){
        b[i] = lower_bound(a.begin(), a.end(), tmp[i])-a.begin()+1;
        updatep(1,1,n,b[i],1);
        updatec(1,1,n,b[i], tmp[i]);
    }

    dac(1, start, start, N);
    cout << ans << "\n";



    

  


}
