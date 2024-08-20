#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,s; cin >> n >> s;

        cout << s / (n/2+1) << "\n";
    }
}