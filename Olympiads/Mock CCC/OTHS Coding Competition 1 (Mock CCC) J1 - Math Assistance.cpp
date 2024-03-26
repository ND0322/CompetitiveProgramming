#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int x,y; cin >> x >> y;

    cout << (x+y) * ((bool)x & (bool)y) << "\n";
}