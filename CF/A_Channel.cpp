#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, a, q; cin >> n >> a >> q;

        string s; cin >> s;

        if(n == a){
            cout << "YES\n";
            continue;
        }

        int tot = a;
        int big = a;

        for(int i = 0; i < q; i++){
            if(s[i] == '+'){
                a++;
                tot++;
                big = max(big, a);

            }
            else a--;
        }

        if(big >= n){
            cout << "YES\n";
            continue;
        }

        if(tot >= n){
            cout << "MAYBE\n";
            continue;
        }

        cout << "NO\n";


    }
}