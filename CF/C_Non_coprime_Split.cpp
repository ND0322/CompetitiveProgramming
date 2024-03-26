#include <bits/stdc++.h>
#include <iostream>


using namespace std;



bool prime[10000005];

//if not prime just find the first factor and split it into n-1 and 1 times the other factor


int main(){
    memset(prime, true, sizeof(prime));

    for(int x = 2; x * x <= 10000000; x++){
        if(prime[x]){
            for(int i = x*x; i <= 10000000; i += x){
                prime[i] = false;
            }
        }
    }

    int tt; cin >> tt;

    while(tt--){
        int l,r; cin >> l >> r;

        if(r <= 3){
            cout << "-1\n";
            continue;
        }

        if(l == r && prime[l]){
            cout << "-1\n";
            continue;
        }

        int x=max(4,l);
        

        if(prime[x]) x = l+1;

        for(int i = 2; i * i <= x; i++){
            if(!(x % i)){
                cout << x / i << " " << (i-1) * (x/i) << "\n";
                break;
            }
        }




    }


}
