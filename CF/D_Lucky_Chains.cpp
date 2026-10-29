#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e7+2;

int prime[MAXN];


/*
first k such that 
x+k not coprime y+k

WLOG let x < y and that x and y are coprime 

y+k = a(x+k)

y+k = ax + ak

y = ax + (a-1)k
2 7 -> 3 8 -> 4 9 -> 5 10 -> 6 11 -> 7 12 -> 8 13 -> 9 14 -> 10 15 
distance always stays the same 


gcd(a,b) = gcd(a + kb, b)
gcd(x+d+k, (x + k)) != 1
gcd(d, x+k) != 1

for each prime factor of d 
we can take x % p to find how many rotations are needed 


*/
int main(){
    int tt; cin >> tt;

    for(int i = 1; i < MAXN; i++) prime[i] = 1;


    for(int i = 2; i < MAXN; i++){
        if(prime[i] == 1){
            for(int j = i; j < MAXN; j += i){
                if(prime[j] == 1) prime[j] = i;
            }
        }
    }

    while(tt--){
        int x,y; cin >> x >> y;

        if(y == x+1){
            cout << "-1\n";
            continue;
        }

        int d = y-x;

        set<int> p;

        while(d > 1){
            p.insert(prime[d]);
            d /= prime[d];
        }



        int ans = 1e9;

        for(int i : p){
            if(x % i == 0) ans = 0;
            ans = min(ans, i - (x % i));
        }
        

        cout << ans << "\n";
        

        
    }
}