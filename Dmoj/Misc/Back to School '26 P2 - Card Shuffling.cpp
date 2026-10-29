#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 1e6+5;

int n, a[MAXN];


int main(){
    cin >> n;

    for(int i = 1;i <= n; i++) cin >> a[i];

    //merge sort

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] < a[i-1]) cnt++;
    }

    cnt++;

    cout << ceil(log2(cnt)) << "\n";
}