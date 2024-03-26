#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int a[105];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];

        if(!(n & 1)){
            cout << "2\n";
            cout << "1 " << n << "\n";
            cout << "1 " << n << "\n";
        }
        else{
            cout << "4\n";

            cout << "1 2\n";

            cout << "1 2\n";

            cout << "2 " << n << "\n";
            cout << "2 " << n << "\n";


        }

        
    }
}