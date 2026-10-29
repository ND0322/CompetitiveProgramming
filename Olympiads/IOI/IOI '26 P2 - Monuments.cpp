#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long get_cost(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();

    long long ans = 0;

    sort(a.begin(), a.end());

    for(int i = 0; i < n/2; i++) ans += a[n-i+1] - a[i];

    if(n&1) ans += a[n/2];
}


int main(){
    get_cost({2, 2, 2, 3}, {})
}