#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n, k; cin >> n >> k;

    if(k == n){
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
        return 0;
    }

    if(k == 1){
        for(int i = 2; i <= n; i++) cout << i << " ";
        cout << "1\n";
        return 0;
    }

    k--;

    int a[n+2];


    for(int i = 1; i <= n; i++) a[i+1] = i;

    for(int i = n-k+1; i <= n; i++) a[i] = i;

    a[1] = n-k;

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";




}