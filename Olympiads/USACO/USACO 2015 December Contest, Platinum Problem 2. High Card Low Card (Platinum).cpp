#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN], b[MAXN];

long long pref[MAXN], suf[MAXN];

struct Node {
    int val;
    int state[2] = {};
} st[MAXN<<2];


Node comb(Node x, Node y){
	Node tmp;
    tmp.val = x.val + y.val + min(x.state[0], y.state[1]);
    tmp.state[0] = x.state[0] + y.state[0] - min(x.state[0], y.state[1]);
    tmp.state[1] = x.state[1] + y.state[1] - min(x.state[0], y.state[1]);
	return tmp;
}
void update(int node, int l, int r, int i, bool t){
    if(l > i || i > r) return;
    if(l == r){
        st[node].state[t] += 1;
        return;
    }

    int mid = (l+r)>>1;

    update(node<<1, l, mid, i, t);
    update(node<<1|1, mid+1, r, i, t);
    st[node] = comb(st[node<<1], st[node<<1|1]);
    
}

bool have[MAXN];

int main(){

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        have[a[i]] = 1;
    }

    int i =1 ;

    for(int j = 2*n; j >= 1; j--){
       
        if(!have[j]) b[i++] = j;
        
    }

    //for(int i = 1; i <= n; i++) cout << a[i] << "\n";
    //for(int i = 1; i <= n; i++) cout << b[i] << "\n";

    for(int i = 1; i <= n; i++){
        //cout << a[i] << "\n";
        //cout << a[i] << " " << b[i] << "\n";
        update(1,1,n<<1, a[i], 0);
        update(1,1,n<<1, b[i], 1);
        pref[i] = st[1].val;
        //cout << st[1].val << "\n";
    }

    memset(st,0, sizeof(st));

    for(int i = n; i >= 1; i--){
        update(1,1,n<<1, a[i], 1);
        update(1,1,n<<1, b[i], 0);
        suf[i] = st[1].val;
    }    

    //for(int i = 1; i <= n; i++) cout << pref[i] << " ";
    //cout << "\n";



    long long ans = 0;

    for(int i = 0; i <= n; i++) ans = max(ans, pref[i] + suf[i+1]);
    cout << ans << "\n";

}