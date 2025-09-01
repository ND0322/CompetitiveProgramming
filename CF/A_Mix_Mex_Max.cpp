#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//mex can either be 0 1 or 2 
//works for only mex 0


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        set<int> s;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            s.insert(x);
        }

        if(s.size() > 2){
            cout << "NO\n";
            continue;
        }

        if(s.size() == 2 && s.find(-1) == s.end()){
            cout << "NO\n";
            continue;
        }

        if(s.find(0) != s.end()){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}