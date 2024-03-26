#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,q; cin >> n >> q;

        vector<int> a(n);

        map<int,int> f,l;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            l[a[i]] = i;
        }

        for(int i = n-1; i >= 0; i--) f[a[i]] = i;

        while(q--){
            int a,b; cin >> a >> b;

            if(f.find(a) == f.end() || f.find(b) == f.end()){
                cout << "NO\n";
                continue;
            }

            cout << (l[b] > f[a] ? "YES\n" : "NO\n");
        }

        
    }
}