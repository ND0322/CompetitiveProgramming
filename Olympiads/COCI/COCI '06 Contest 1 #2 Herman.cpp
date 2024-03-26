#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//the manhattan circle will be a rotated square with the lattice points
//area is sqrt(r^2 + r^2)^2
//2 * r^2

int main(){
    int r; cin >> r;
    
    cout << setprecision(4) << fixed << 3.1415926535 * r * r << "\n";
    cout << setprecision(4) << fixed << 2.0 * r*r << "\n";
}