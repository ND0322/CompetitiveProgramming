#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//1 1 2 3 4 5 ... 1
//n-2 + n-1 arrays

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        cout << "1 ";

        for(int i = 1; i < n-1; i++) cout << i << " ";
        cout << "1\n";
    }
}