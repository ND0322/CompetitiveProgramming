#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e6+3;

int n, s[MAXN], t[MAXN];

pair<int,int> st[MAXN<<2];

void update(int node, int l, int r, int i, int x){
    if(l == r){
        st[node].first += x;

        if(!st[node].first) st[node].second = 0;
        else st[node].second = l;
        return;
    }


    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1,l, mid, i, x);
    else update(node<<1|1, mid+1,r,i,x);


    if(!st[node<<1].second) st[node].second = st[node<<1|1].second;
    else if(!st[node<<1|1].second) st[node].second = st[node<<1].second;
    else st[node].second = min(st[node<<1].second, st[node<<1|1].second);

    if(!st[node<<1].second){
        st[node].first = st[node<<1|1].first;
        return;
    }

    if(!st[node<<1|1].second){
        st[node].first = st[node<<1].first;
        return;
    }
    if(st[node<<1].first + st[node<<1].second > st[node<<1|1].second) st[node].first = st[node<<1].first + st[node<<1|1].first;
    else st[node].first = st[node<<1|1].first + st[node<<1|1].second - st[node<<1].second; 

    cout << st[node].first << " " << st[node].second << "\n";
    cout << l << " " << r << " " << st[node<<1].second << " " << st[node<<1].first << " " << st[node<<1|1].second << " " << st[node<<1|1].first << "\n";
}

/*
consider the brute force solution

there will be dominators in which case the prefix is reset
we should keep track of the rightmost dominator in each range 
*/

int main(){

    int q; cin >> q;
    int cnt = 0;
    int ans = 0;

    //for(int i = 1; i <= 4e6; i++) st[i] = {-1, 0};
    for(int i = 1; i <= q; i++){
        char c; cin >> c;

        if(c == 'A'){
            cnt++;
            cin >> s[cnt] >> t[cnt];

            //s[cnt] = (s[cnt] + ans) % MOD;
            //t[cnt] = (t[cnt] + ans) % MOD;
            update(1,1,1e6, s[cnt], t[cnt]);
        }
        if(c == 'D'){
            int id; cin >> id;

            //id = (id + ans) % MOD;

            update(1,1,1e6,s[id], -t[id]);
        }

        ans= st[1].first + st[1].second - 1;
        cout << ans << "\n";

    }
}

//6 + 5 + 2 = 13
//15 + 1 