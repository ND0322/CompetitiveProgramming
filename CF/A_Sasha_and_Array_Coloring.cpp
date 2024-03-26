#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(),arr.end());

        int ans = 0;

        for(int i = 0; i < n/2; i++){
            ans+= arr[n-i-1] - arr[i];
        }

        cout << ans << "\n";
    }
}