#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        map<int,int> ind;
        set<int> b;
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];

            b.insert(a[i]);
        }

        while(b.size()){
            ind[*b.rbegin()] = b.size();
            b.erase(prev(b.end()));
        }

        bool flag = 1;



        for(int i = 1; i < n; i++){
            if((ind[a[i]] & 1) == (ind[a[i+1]] & 1)) flag =0;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}