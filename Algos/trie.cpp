#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int tr[MAXN][26], cnt[MAXN], col[MAXN], tot;
void insert(string s) {
    int t, u = 0;
    for (int i = 0; i < s.size(); i++) {
        t = s[i] - 'A';
        if (!tr[u][t]) tr[u][t] = ++tot;
        
        u = tr[u][t];
        col[u] = t;
    }
    cnt[u]++;
}
int query(string s) {
    int t, u = 0;
    for (int i = 0; i < s.size(); i++) {
        t = s[i] - 'a';
        if (!tr[u][t]) return 0;
        
        u = tr[u][t];
        col[u] = t;
    }
    return cnt[u];
}

int main(){
    while(1){
        string s; cin >> s;

        if(s.empty()) break;

        insert(s);
        //cout << tot << "\n";
    }

    cout << tot+1 << "\n";
}