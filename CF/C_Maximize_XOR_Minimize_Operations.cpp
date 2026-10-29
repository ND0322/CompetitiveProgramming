#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
dp
digit and carry
*/


int msb(int x){
    if(!x) return -1;
    return 31 - __builtin_clz(x);
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int x,y; cin >> x >> y;

        int z = x+y;

        cout << z << " ";

        int r = msb(x+y);

        int moves = 0;

        for(int i = r; i >= 0; i--){
            if(!(z>>i)&1) continue;

            if((x>>i)&1 != (y>>i)&1) continue;

            //both 0
            //if next is 1 we'll get ride of it

            if(z>>(i))

        }
    }

    
}
