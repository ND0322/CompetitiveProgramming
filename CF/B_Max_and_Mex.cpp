#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

//two cases
//a is consecutive integers
//ans will be n + k
//otherwise nothing will change

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> a(n+1);

        set<int> s;

        for(int i = 1; i <= n; i++){
            cin >> a[i];

            s.insert(a[i]);
        }

        int cur = 0;

        for(int i : s){
            if(cur == i) cur++;
        }

        if(cur == s.size()) cout << s.size() + k << "\n";
        else{
            if(k) s.insert(ceil((cur + *s.rbegin()) / 2.0));
            cout << s.size() << "\n";
        }
    }
}