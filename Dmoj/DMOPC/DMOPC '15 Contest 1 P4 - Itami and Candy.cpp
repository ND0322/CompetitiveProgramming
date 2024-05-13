#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, x;

bool prime[MAXN];

int main(){
    cin >> n >> x;
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for(int i = 2; i*i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j+=i) prime[j] = 0;   
        }
    }



    long long ans = 0;



    for(int i = 1; i <= n; i++){
        if(!prime[i]) continue;
        
        //give 0
        if(n-i >= 0) ans += (n-i)/x+1;
        if(n-i-1 >= 0) ans += (n-i-1)/x+1;
    }

    cout << ans << "\n";


}