#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n, k, m; cin >> n >> k >> m;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1){
        cout << a[0] + k << "\n";
        return 0; 
    }

    long long ans = min(a[0]+k, a[1]);

    for(int i = 1; i < n-1; i++){
        int l = max(a[i-1], a[i]-k);
        int r = min(a[i+1], a[i]+k);

        ans = max(ans,  (long long)a[i+1] - l);
        ans = max(ans, (long long)r - a[i-1]);

    }

    


}