#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 7005;

int n, k;

bool prime[MAXN];

int main(){
    cin >> n >> k;

    fill(prime, prime+n+1, true);

    for(int i = 2; i * i <= n; i++) if(prime[i]) for(int j = i * i; j <= n; j+=i) prime[j] = false;

    if(k > 3){
        cout << "0\n";
        return 0;
    }

    int ans = 0;

    for(int i = 2; i <= n; i++){
        int sum = 0;

        if(prime[i]){
            sum = 1;
        }
        else{
            if(i&1){
                if(prime[i-2]) sum = 2;
                else sum = 3;
            }
            else
                sum = 2; 
        }

        ans += (sum == k);
        
    }

    cout << ans << "\n";
        
    
}