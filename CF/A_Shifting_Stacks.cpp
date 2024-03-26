#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        long long sum = 0;
        bool flag = 1;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            sum += x;

            if(sum < i){
                flag = 0;
                continue;
            }

            sum -= i;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}