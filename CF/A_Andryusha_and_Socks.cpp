#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int n; cin >> n;

    set<int> act;

    int ans = 0;
    for(int i = 0; i < 2*n; i++){
        int x; cin >> x;

        if(act.find(x) == act.end()) act.insert(x);
        else act.erase(x);

        ans = max(ans, (int)act.size());
    }

    cout << ans << "\n";
}