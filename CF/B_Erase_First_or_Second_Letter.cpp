#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;


const int MAXN = 1e5+5;






int main(){
    int tt; cin >> tt;

    while(tt--){
        set<int> s;

        int n; cin >> n;

        int cur = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            char c; cin >> c;

            if(s.find(c) != s.end()) cur++;
            ans += cur;
            s.insert(c);
        }

        cout << n * (n+1LL) / 2 - ans << "\n";
    }
}

/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/