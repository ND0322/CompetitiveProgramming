#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int tt; cin >> tt;

    while(tt--){
        int n, a, b; cin >> n >> a >> b;

        bool flag = 0;

        if(a < b){
            swap(a,b);
            flag = 1;
        }

        int ans = (1<<n)-1; 

        for(int i = a/(b+1); i < n; i+=a/(b+1)) ans ^= (1<<i);

        ans ^= (1<<n)-1;
        for(int i = 0; i < n; i++) cout << (ans & (1<<i) ? 'R' : 'B');

        cout << "\n";

    }
    
}
