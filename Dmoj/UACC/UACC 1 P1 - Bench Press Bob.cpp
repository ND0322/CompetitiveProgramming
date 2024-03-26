#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    if(n < 45 || n % 45 != 0){
        cout << "Rip Bob!\n";
        return 0;
    }

    cout << (((n-45)/45)&1?"Rip Bob!\n" : "Let's go Bob!\n");


}

/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/