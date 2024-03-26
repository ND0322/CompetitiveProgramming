#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int x,y; cin >> x >> y;

    int ans = 0;

    for(int i = 1; i * i * i *i * i * i <= y; i++){
        if(i*i*i*i*i*i >= x) ans++;
    }

    cout << ans << "\n";

}