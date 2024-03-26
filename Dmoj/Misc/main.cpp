#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, id[MAXN], nxt[MAXN], vis[MAXN];

long long m;

bool weight[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        if(s[0] == 'c') weight[i] = 1;
        else if(s[0] == 'g'){
            string x; cin >> x;

            nxt[i] = x[0] - '0';
        }
        else id[s[0] - '0'] = i;
        vis[i] = -1;
    }

    int cnt = 0;
    int i = 0;
    int cyc = 0;

    while(1){
        cnt += weight[i];
        m -= weight[i];

        cout << i << "\n";

        if(!m){
            cout << i << "\n";
            return 0;
        }

        if(nxt[i] && vis[i] != -1){
            cyc = m % (cnt - vis[i]);
            break;
        }

        if(nxt[i]) i = nxt[i];
        else i++;
    }

    cout << i << " " << cyc << "\n";




}

