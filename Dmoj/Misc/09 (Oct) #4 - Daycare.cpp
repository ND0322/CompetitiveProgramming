#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN];

int main(){
    cin >> n;

    int sum = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int tar = sum/n;




}