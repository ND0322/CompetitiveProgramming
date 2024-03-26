#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e9;


int main(){
 
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        int i = 1;


        while(1){
            if((n - i)/(i<<1)+1 >= k) break;
            k -= (n - i)/(i<<1)+1;
            i<<=1;
        }

        //cout << k << "\n";
        
        //1 + 6 * 2

        //cout << i << " " << (i<<1) << " " << k-1 << "\n";

        cout << i + (k-1) * ((i<<1)) << "\n";

    


    }
}

//2 ^ n, 2^(n+1)


/*
1 3 5 7 9
2 6 10
4 12 
8
*/