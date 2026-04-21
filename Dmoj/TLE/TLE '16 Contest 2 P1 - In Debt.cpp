#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    pair<int,int> mx = {0,0};

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        int x; cin >> x;

        if(s[0] == 'b') cnt += x;
        else cnt -= x;

        mx = max(mx, {cnt, -i});
    }

    cout << -mx.second << "\n";
}