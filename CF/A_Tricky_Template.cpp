#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string a,b,c; cin >> a >> b >> c;

        if(b == c || a == c){
            cout << "NO\n";
            continue;
        }

       


        bool flag = 1;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i] && c[i] != a[i]){
                cout << "YES\n";
                flag = 0;
                break;
            }

            if(c[i] != a[i] && c[i] != b[i]){
                cout << "YES\n";
                flag = 0;
                break;
            }
        }

        if(flag) cout << "NO\n";
    }
}


/*
try to solve a quickly
b go with your instinct instead of just sitting there
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/