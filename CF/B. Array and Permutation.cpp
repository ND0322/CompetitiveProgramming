#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        vector<int> pos(n+1);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pos[a[i]] = i;
        }

        for(int i = 1; i <= n; i++) cin >> b[i];

        vector<int> ord;

        int i = 1;

        while(i <= n){
            int x = b[i];

            while(i <= n && b[i] == x) i++;

            ord.push_back(x);
        }

        i = 0;
        bool flag = 1;
        for(int x : ord){
            if(pos[x] < i){
                flag = 0;
                break;
            }

            i = pos[x];
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}