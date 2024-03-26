#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//1 3 2 4
//1 4 2 5 3
//1 6 2 5 3 4

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int i = 1;
        int j = n;

        while(i < j){
            cout << i++ << " ";
            cout << j-- << " ";
        }

        if(n&1) cout << i << " ";
        cout << "\n";
    }
}