#include <bits/stdc++.h>
#include <iostream>

using namespace std;


pair<long long,long long> f(long long x, int k){
    if(x < k) return {0,0};
    pair<int,int> res = f((1+x)/2-1, k);
    res.first *= 2;
    res.first += res.second * ((1+x)/2);
    if(x&1){
        res.first += (1+x)/2;
        res.second++;
    }

    return res;


}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        cout << f(n,k).first << "\n";
    }
}