#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

int n;

int query(int x, int y){
    cout << "0 " << x << " " << y << "\n";
    int res; cin >> res;
    return res;
}

void update(int x, int y){
    cout << "1 " << x << " " << y << "\n";
}

/*
for the dac
have a vector of stuff for each array
split into two groups: stuff smaller and stuff larger than this mid
*/

void dac(vector<int> a, vector<int> b){
    if(!a.size()) return;

    int mid = a[(int)a.size()/2];
    int ind = 0;

    vector<int> l,r;

    for(int i : b){
        int res = query(mid, i);

        if(res == -1) l.push_back(i);
        if(res == 1) r.push_back(i);
        if(!res) ind = i;
    }

    vector<int> la, ra;

    for(int i : a){
        if(i == mid) continue;
        int res = query(i, ind);

        if(res == -1) ra.push_back(i);
        if(res == 1) la.push_back(i);
    }

    update(mid, ind);
    dac(la,l);
    dac(ra,l);
}

int main(){
    cin >> n;

    vector<int> a,b;

    for(int i = 1; i <= n; i++){
        a.push_back(i);
        b.push_back(i);
    }

    dac(a,b);
    
}