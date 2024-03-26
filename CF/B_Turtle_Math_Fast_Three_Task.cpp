#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int cnt[3] = {0,0,0};

        int sum = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            sum = (sum + x) % 3;
            cnt[x%3]++;
        }

        if(!sum){
            cout << "0\n";
            continue;
        }

        if((sum+1)%3 == 0){
            cout << "1\n";
            continue;
        }

        if(cnt[1] && (sum-1) % 3 == 0){
            cout << "1\n";
            continue;
        }

        if(cnt[2] && (sum-2) % 3 == 0){
            cout << "1\n";
            continue;
        }

        cout << "2\n";
    }
}