#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        //odds print n ones

        //otherwise print n-2 twos and 1 and 3

        if(n&1) for(int i = 1; i <= n; i++) cout << "1 ";
        else{
            cout << "1 3 ";
            for(int i = 3; i <= n; i++) cout << "2 ";
        }

        cout << "\n";
        
    }
}