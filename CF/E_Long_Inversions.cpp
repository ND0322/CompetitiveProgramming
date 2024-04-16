#include <bits/stdc++.h>
#include <iostream>

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

using namespace std;

const int MAXN = 5005;

int n, st[MAXN<<1];

string s;

//bruteforce k then greedily check


void update(int l, int r){
    for(l += n, r+=n; l < r; l>>=1, r>>=1){
        if(l&1) st[l++]++;
        if(r&1) st[--r]++;
    }
}

int query(int i){
    int ans = 0;
    for(i+=n; i; i>>=1) ans += st[i];
    return ans;
}


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        cin >> s;

        for(int i = n; i >= 1; i--){
            memset(st,0,sizeof(st));

            //cout << i << "\n";

            for(int j = 0; j < n; j++){
                if(s[j] == '1') update(j,j+1);
            }

             
            for(int j = 0; j < n-i+1; j++){
                if(query(j) & 1) continue;
                update(j, j+i);         
            }

            

            bool flag = 1;
            for(int j = n-i; j < n; j++) flag &= (query(j) & 1);
            if(flag){
                cout << i << "\n";
                break;
            }

            
        }
    }
}