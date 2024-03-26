#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 150005;

int ans[MAXN], n, m, st[MAXN<<1], gc[MAXN<<1];

vector<pair<pair<int,int>, int>> queries;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}


void update(int l, int r, int x){
    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1){
            st[l] = lcm(st[l], x);
            l++;
        }
        if(r&1){
            r--;
            st[r] = lcm(st[r],x);
        }
    }
}

int query(int i){
    int ans = 1;
    for(i += n; i > 0; i>>=1) ans = lcm(ans,st[i]);
    return ans; 
}

void build(){
    for(int i = n-1; i > 0; i--) st[i] = gcd(st[i<<1], st[i<<1|1]);
}

int queryg(int l, int r){
    int ans = 0;
    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans = gcd(ans, st[l++]);
        if(r&1) ans = gcd(ans, st[--r]);
    }
    return ans;
}


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    fill(ans, ans+n+1, 1);
    fill(st, st+2*n+1, 1);

    while(m--){
        int l,r,x; cin >> l >> r >> x;
        queries.push_back({{l,r},x});

        update(l,r+1,x);
    }

    for(int i = 1; i <= n; i++) ans[i] = query(i);
    fill(st, st+2*n+1, 0);

    for(int i = 1; i <= n; i++) st[i+n] = ans[i];

    build();



    for(pair<pair<int,int>, int> i : queries){
        if(i.first.first == i.first.second){
            if(ans[i.first.first] != i.second){
                cout << "Impossible\n";
                return 0;
            }
        }
        else if(queryg(i.first.first, i.first.second+1) != i.second){
            cout << "Impossible\n";
            return 0;
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}