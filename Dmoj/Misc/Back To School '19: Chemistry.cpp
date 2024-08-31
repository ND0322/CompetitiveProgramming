#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//log(k+1) of n <= m

int logba(long long a, int b){
    return ceil(log2(a) / log2(b));
}

int main(){
    long long n, m; cin >> n >> m;

    for(int i = 1; i <= 100000; i++){
        if(logba(n, i+1) <= m){
            cout << i << "\n";
            return 0;
        }
    }
}

