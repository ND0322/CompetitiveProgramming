#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
assume k is odd
we can just do n * k

if k is even 
choose 2 numbers to xor such that their sum is max

if n[i] is 1 -> one 0 and one 1
else 2 1s 
*/

int msb(int n){
    return 31 - __builtin_clz(n);
}


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<vector<vector<int>>> dp(32, vector<vector<int>> (2, vector<int>(2, 0)));
        vector<vector<vector<int>>> rebuild(32, vector<vector<int>> (2, vector<int>(2, 0)));

        if(k&1){
            for(int i =1 ; i <= k; i++) cout << n << " ";
            cout << "\n";
            continue;
        }


        for(int i = 1; i <= k-2; i++) cout << n << " ";

        int a = 0;
        int b = 0;


        bool c = 0;
        bool d = 0;

        for(int i = msb(n); i >= 0; i--){
            if((n >> i) & 1){
                if(!c){
                    //a is not yet smaller, add 0 to a
                    c = 1;
                    b += (1<<i);
                }
                else{
                    d = 1;
                    a += (1<<i);
                }
            }

            else{
                if(c && d){
                    a += (1<<i);
                    b += (1<<i);
                }
                
            }

        }
        
        cout << a << " " << b << "\n";
         
    }

}