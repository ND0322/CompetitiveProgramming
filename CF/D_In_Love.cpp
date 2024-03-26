#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int q;

multiset<int> l, r;

int main(){
    cin >> q;

    while(q--){
        char type; cin >> type;

        if(type == '+'){
            int x,y; cin >> x >> y;

            l.insert(x);
            r.insert(y);
        }
        else{
            int x,y; cin >> x >> y;

            l.erase(l.find(x));
            r.erase(r.find(y));
        }

        cout << ((!(l.empty()) && (*l.rbegin() > *r.begin())) ? "YES\n" : "NO\n");
    }
}