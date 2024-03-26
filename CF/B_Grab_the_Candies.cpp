#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int se = 0;
        int so = 0;
        int n; cin >> n;

        while(n--){
            int x; cin >> x;


            if(x % 2 == 0){
                se += x;

            }
            else{
                so+=x;
            }
        }


        if(se > so){
            cout << "YES\n"; 
        }
        else{
            cout << "NO\n";
        }
    }
}