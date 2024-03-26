#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int a=0;
        int b=0;
        int cnta = 0;
        int cntb = 0;

        bool flag = true;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(x == a){
                cnta++;
                continue;
            }
            if(x == b){
                cntb++;
                continue;
            }

            if(!a){
                a = x;
                cnta++;
                continue;
            }

            if(!b){
                b = x;
                cntb++;
                continue;
            }

            flag = false;
            
        }

        if(a && !b){
            cout << "YES\n";
            continue;
        }

        if(flag) cout << (min(cnta,cntb) == n/2 ? "YES\n" : "NO\n");
        else cout << "NO\n";


    }
}