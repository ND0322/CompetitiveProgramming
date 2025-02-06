#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        long long n; cin >> n;

        if(n <= 3){
            cout << "1\n";
            continue;
        }

        

        cout << (1<<(int)(log2(n) / log2(4))) << "\n";
    }
}