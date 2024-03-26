#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 60;

#define int long long

long long a,b,r;

map<int,int> dp[MAXN];


//try to get rid of indices where they differ

int msb(int x){
    return 64 - __builtin_clzll(x);
}





int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> a >> b >> r;

        if(a < b) swap(a,b);

        
        int i = 61;

        long long x= 0;


        bool flag = 1;

        while(i >= 0){
            if((a & (1LL<<i)) && !(b & (1LL<<i))){
                if(flag) flag = 0;
                else if((x ^ (1LL<<i)) <= r) x ^= (1LL<<i);
            }
            i--;
        }

        cout << abs((a ^ x) - (b^x)) << "\n";
        
        
    }

    
    

    
}