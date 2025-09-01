#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        set<int> s;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            s.insert(x);
        }


        cout << ((int)s.size() == n ? "NO\n" : "YES\n");

    }
}