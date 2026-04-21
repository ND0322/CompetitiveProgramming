#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];


        for(int i = 1; i < n; i++){
            if(a[i] < k){
                a[n] += a[i];
                k -= a[i];
                a[i] = 0;
            }
            else{
                a[i] -= k;
                a[n] += k; 
                break;
            }
        }

        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n"; 
    }
}