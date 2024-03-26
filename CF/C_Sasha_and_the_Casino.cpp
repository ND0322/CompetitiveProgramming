#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve(){
    int k,x,a; cin >> k >> x >> a;

    //bet min amount to make up for the last bet + 1

    //cnt * k >= debt + 1
    //cnt >= (debt+1)/k

    k--;

    long long debt = 0;
    for(int i = 1; i <= x+1; i++){
        int cnt = (debt + k)/k;
        debt += cnt;

        

        if(debt > a){
            cout << "NO\n";
            return;
        }
    }   

    cout << "YES\n";
}

int main(){
    int tt; cin >> tt;

    while(tt--) solve();
}