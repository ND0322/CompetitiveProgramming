#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;
int n;

int main(){
    cin >> n;

    long long sum = 0;
    int mx = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        sum += x;
        mx = max(mx,x);
    }

    cout << min(sum - mx, sum/2) << "\n";
}
