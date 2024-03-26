#include <bits/stdc++.h>
#include <iostream>
#include <queue>


using namespace std;

const int MAXN = 2e5+5;

int n, best[MAXN], st[MAXN<<1];

vector<int> a[MAXN];

priority_queue<int> pq;


void update(int i, int x){
    for(st[i+=n] += x; i > 0; i>>=1) st[i>>1] = st[i] + st[i^1];
}

long long query(int r){
    long long ans = 0;
    int l = n;
    for(r += n; l < r; l >>=1, r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }
    return ans;
}


int main(){
    cin >> n;


    vector<int> b(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x].push_back(i);
        b[i] = x;
    }

    sort(b.begin(),b.end());

    //checking existence of answer

    for(int i = 0; i < n; i++){
        if(b[i]-1 < i){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i = n; i >= 1; i--){
        for(int j : a[i]) pq.push(j);
        best[i] = pq.top();
        pq.pop();
    }

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        ans += i-1-query(best[i]+1);
        update(best[i], 1);
    }

    cout << ans << "\n";










}