#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e6+5;

int n, a[MAXN];

int main(){

    cin >> n;

    for(int i = 0; i < n; i++ ) cin >> a[i];

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == a[(i+n/2)%n]) cnt++;
    }

    cout << cnt << "\n";
}