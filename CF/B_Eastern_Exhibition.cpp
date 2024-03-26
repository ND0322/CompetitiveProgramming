#include <bits/stdc++.h>
#include <iostream>


using namespace std;





int main() {
    int tt; cin >> tt;

    while(tt--){
        int n;
        cin >> n;
        vector<long long> x(n), y(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i] >> y[i];
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        cout << (x[x.size() / 2] - x[(x.size() - 1) / 2] + 1) * (y[y.size() / 2] - y[(y.size() - 1) / 2] + 1) << "\n";
    }
}