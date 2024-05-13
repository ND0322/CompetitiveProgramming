#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int query(int i){
    cout << "? " << i << "\n";
    int x; cin >> x;
    return x;
}


int main(){
    int n; cin >> n;

    int lo = 1;
    int hi = n;

    while(lo < hi){
        int mid = (lo+hi)>>1;
        int a = query(mid);
        int b = query(mid+1);

        if(a < b) hi = mid;
        else lo = mid+1;
    }

    cout << "! " << lo << "\n";
}