#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

#define int long long


//full needs some data structures
//a min segtree and some fenwicks or just segtrees
//ill use iterative segtrees for all

int n, q, a[MAXN], t[MAXN<<1][4];

pair<int,int> st[MAXN<<1];

long long ans = 0;

set<int> suf;

//t[0] is removed indices
//t[1] is removed values
//t[2] is marked indices
//t[3] is marked values
//we mark stuff when contribute them to the answer
//t could be replaced with a BIT


void add(int i, int x, int typ){
    for(t[i+=n][typ] += x; i > 1; i >>=1) t[i>>1][typ] = t[i][typ] + t[i^1][typ];
}

int queryf(int l, int r, int typ){
    int ans = 0;

    for(l += n, r+=n; l < r; l >>=1, r>>=1){
        if(l&1) ans += t[l++][typ];
        if(r&1) ans += t[--r][typ];
    }
    return ans;
}

pair<int,int> comb(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first) return {a.first, a.second};
    else return {b.first,b.second};
    

}

void build(){
    for(int i = n-1; i > 0; i--) st[i] = comb(st[i<<1], st[i<<1|1]);
}

void update(int i, int x){
    i += n;
    for(st[i] = {x,st[i].second}; i > 1; i >>=1) st[i>>1] = comb(st[i], st[i^1]);
}

pair<int,int> query(int l, int r){
    pair<int,int> ans = {n, -1};

    for(l += n, r +=n; l < r; l>>=1, r>>=1){
        if(l&1) ans = comb(ans, st[l++]);
        if(r&1) ans = comb(ans,st[--r]);
    }
    return ans;
}

//when we mark stuff
//we add it to the suffix
//we change marked index i to true
//we change marked value i to true
//we contribute to the answer i - removed before i - (val[i] - removed values )

//to revert
//remove the contribution
//remove the marking
//update neighbors 
//remove from suffix



void revert(int i){
   
    add(i, -1LL, 2);
    add(a[i], -1LL, 3);
    ans -= (i - queryf(0, i+1LL, 0)) - (a[i] - queryf(0,a[i]+1LL, 1));

    int l = n, r = 0;

   
    //🙈 im bald
    if(suf.find(i) != suf.end()) r = (++suf.find(i) == suf.end() ? n : *(++suf.find(i)));
    l = (suf.find(i) == suf.begin() ? 0 : *(suf.find(i)--) + 1);

    suf.erase(suf.find(i));

    while(l < r){
        pair<int,int> tmp = query(l, r);
        if(tmp.first == n) break;

        if(tmp.first < (r == n ? n : a[r])){
            //mark this
            suf.insert(tmp.second);
            add(tmp.second, 1, 2);
            add(tmp.first, 1, 3);
            ans += (tmp.second - queryf(0, tmp.second+1LL, 0)) - (tmp.first - queryf(0, tmp.first+1LL, 1));
        }

        l = tmp.second+1;



    }
    



   
}



int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    for(int i = 0; i <= 2*n; i++) st[i] = {1e9,-1}; 
    

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        st[i+n] = {a[i], i};
    }

    
    build();

   

    int cur = n;
    for(int i = n-1; i >= 0; i--){
        cur = min(a[i], cur);
        if(a[i] == cur){
            ans += i-a[i];
            suf.insert(i);
            add(i, 1LL, 2);
            add(a[i], 1LL, 3);
            
        }
    }

    cout << (ans += n) << " ";

    while(q--){
        int i; cin >> i;
        i--;

        //nullify this element

        update(i, n);

       

        if(suf.find(i) != suf.end()){
            revert(i);    

           
        }

        //cout << "yes\n";  

        //cout << queryf(i, n, 2) << "\n";
        //cout << queryf(a[i], n, 3) << "\n";
        ans -= queryf(i, n, 2);
        ans += queryf(a[i], n, 3);

        add(i, 1LL, 0);
        add(a[i], 1LL, 1);

        

        ans--;


        
        cout << ans << " ";


        

    }

    cout << "\n";
}

//385 381 376 372 367 363 359 354 350 346 342 337 333 328 323 318 314 309 305 300 295 291 286 282 278 274 269 264 259 255 251 247 242 238 233 229 226 221 217 213 211 206 203 198 193 188 184 179 175 170 166 162 157 153 148 143 138 133 129 124 156 153 150 146 143 140 138 134 132 128 125 122 118 116 113 111 107 103 100 97 94 90 86 82 78 75 72 69 66 62 60 57 55 51 47 43 40 36 132 239


