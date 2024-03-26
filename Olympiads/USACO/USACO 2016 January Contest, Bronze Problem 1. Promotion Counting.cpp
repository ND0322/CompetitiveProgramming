#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    freopen("promotion.in", "r", stdin);
    freopen("promotion.out", "w", stdout);
    int a,b; cin >> a >> b;

    int nw = b-a;

    cout << nw << "\n";

    cin >> a >> b;

    nw -= (b-a);

    cout << nw << "\n";

    cin >> a >> b;

    nw -= (b-a);

    cout << nw << "\n";

    cin >> a >> b;



}