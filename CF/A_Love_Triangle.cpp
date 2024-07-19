#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int n, adj[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> adj[i];

    for(int i = 1; i <= n; i++){
        if(adj[adj[adj[i]]] == i){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

}