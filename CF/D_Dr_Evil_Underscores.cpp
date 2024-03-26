#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n;

vector<int> a;

int dac(vector<int> cur, int bit){
    if(bit < 0) return 0;

    vector<int> l, r;

    for(int i : cur){
        if(i & (1<<bit)) l.push_back(i);
        else r.push_back(i);
    }

    if(!l.size()) return dac(r, bit-1);
    if(!r.size()) return dac(l, bit-1);

    return min(dac(l, bit-1), dac(r,bit-1)) + (1<<bit);
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        a.push_back(x);
    }

    cout << dac(a, 30) << "\n";




    
}