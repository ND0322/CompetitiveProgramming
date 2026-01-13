#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

/*
for evens

steven will always make even
for todd evens preseve game state 
*/

int32_t main(){
    int n; cin >> n;

    int cnt = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        cnt += x & 1;
    }

    if((n-cnt >= cnt) || (n&1)) cout << "Steven\n";
    else cout << "Todd\n";

    
}