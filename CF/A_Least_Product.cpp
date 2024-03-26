#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        int cnt = 0;
        bool flag = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            cnt += (a[i] < 0);
            flag |= (a[i] == 0);
        }

        if(flag){
            cout << "0\n";
            continue;  
        }

        if(cnt & 1){
            cout << "0\n";
        }
        else cout << "1\n1 0\n";
        
    }
}

/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/