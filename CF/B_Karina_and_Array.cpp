#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(),arr.end());

        cout << max(arr[n-1] * arr[n-2],arr[0] * arr[1]) << endl;
    }
}