#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
All numbers between min and max for some length are valid

generate all intervals of all lengths for all bases and union same bases

d = (b-1)L/2
*/

int lg(unsigned long long x) {
  return 64-__builtin_clzll(x);
}

int main(){
    int b, n; cin >> b >> n;

    for(int i = 2; i <= b; i++){
        vector<pair<int,int>> ranges;
    

        for(int j = 1; j < lg(1e18) / lg(i); j++){
            if(((i-1) * j) & 1) continue;

            int targ = ((i-1) * j) / 2;
            
            long long hi = 0;

            long long mult = pow(10, j-1);

            cout << mult << "\n";
            for(int k = 0; k < j; k++){

            }
        }
    }
}