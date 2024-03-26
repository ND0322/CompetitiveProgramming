#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            a.push_back(x);
        }


        int cnt = 1;
        bool flag = 1;

        for(int i = 0; i < n-1; i++){
            if(i+1 == cnt){
                cnt <<= 1;
                continue;
            }
            if(a[i] > a[i+1]){
                flag = 0;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");


    }
}