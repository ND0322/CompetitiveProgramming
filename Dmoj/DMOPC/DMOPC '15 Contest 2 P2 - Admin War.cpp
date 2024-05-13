#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 205;

int n, a[MAXN], b[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    int x = 0;
    int y = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] > b[i]) x++;
        if(a[i] < b[i]) y++;
    }

    cout << x << " " << y << "\n";
    if(x > y) cout << "Xyene\n";
    if(x < y) cout << "FatalEagle\n";
    if(x == y) cout << "Tie\n";
}
