#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    cout << "guess 0\n";

    int res; cin >> res;

    int tmp = res;
    cout << "guess " << res << "\n";

    cin >> res;

    if(!res) cout << "answer " << tmp << "\n";
    else cout << "answer " << -tmp << "\n";
}