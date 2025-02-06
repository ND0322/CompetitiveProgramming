#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//bit by bit
//dp?



int main(){
    int tt; cin >> tt;

    while(tt--){
        int l, r; cin >> l >> r;

        int pos = -1;
        int a = 0;
        int b = 0;

        for(int i = log2(r); i >= 0; i--){

            a += r & (1<<i);
            b += l & (1<<i);
            if((r & (1<<i)) && !(l & (1<<i))){
                pos = i;
                break;
            } 
        }

        while(pos--){
            b += (1<<pos);
        }

        cout << a << " " << b << " ";

        while(l == b || l == a) l++;

        cout << l << "\n";



    }
    
}
