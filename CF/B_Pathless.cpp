#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
parity

if we can get there without exceeding

let k = s - sum(a)

if there is a 0 1 adjacency it can always bypass

if there is a 2 1 adjacency it works for any divisible by 3

2 2 adjacency works for all divisbile by 4

2 0 works for all even numbers 

1 1 works for all even numbers 


0 1 is -1
2 1 is -3
2 2 is -4
2 0 is -2
1 1 is -2

always a 02 and 21


therefore

any even number
any odd number >= 3
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        int cnt[3] = {0,0,0};
        int sm = 0;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            cnt[x]++;
            sm += x;
        }

        if(k - sm < 0){
            for(int i = 0; i < cnt[0]; i++) cout << "0 ";
            for(int i = 0; i < cnt[1]; i++) cout << "1 ";
            for(int i = 0; i < cnt[2]; i++) cout << "2 ";
            cout << "\n";
            continue;
        }

        if((k-sm) % 2 == 0){
            cout << "-1\n";
            continue;
        }

        if(k-sm == 1){
            for(int i = 0; i < cnt[0]; i++) cout << "0 ";
            for(int i = 0; i < cnt[2]; i++) cout << "2 ";
            for(int i = 0; i < cnt[1]; i++) cout << "1 ";
            cout << "\n";
            continue;
        }

        cout << "-1\n";




    }
}

