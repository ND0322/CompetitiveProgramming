#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    
    int n; cin >> n;

    set<int> s;

    int ans = 0;

    for(int i = 1; i <= n; i++) s.insert(i);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        auto it = s.lower_bound(i-x);

        while(it != s.end() && *it < i){
            ans++;
            s.erase(it);
            it = s.lower_bound(i-x);
        }
    }

    cout << n-ans << "\n";
}