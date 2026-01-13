#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        int cnt = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(a[j] > a[i]){
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << "\n";
    }
}