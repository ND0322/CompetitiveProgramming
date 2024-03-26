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

            nxt[i] = stoi(x.substr(0, x.size()-1));
        }
        else id[stoi(s.substr(0, s.size()-1))] = i;
        vis[i] = -1;
    }

    int cnt = 0;
    int i = 0;
    int cyc = 0;

    while(1){

        if(i == n){
            cout << "WA\n";
            return 0;
        }

        cnt += weight[i];
        m -= weight[i];

        if(!m){
            cout << i+1 << "\n";
            return 0;
        }

        

        if(nxt[i] && vis[i] != -1){
            if(!(cnt - vis[i])){
                cout << "TLE\n";
                return 0;
            }
            cyc = m % (cnt - vis[i]);
            break;
        }

        vis[i] = cnt;

        if(nxt[i]) i = id[nxt[i]];
        else i++;
    }

    if(!cyc){
        cout << i-1 << "\n";
        return 0;
    }
    cnt = 0;
    
    while(1){
        cnt += weight[i];

        if(cnt == cyc){
            cout << i+1 << "\n";
            return 0;
        }

        if(nxt[i]) i = id[nxt[i]];
        else i++;
    }
    
    

    

   

   




}

