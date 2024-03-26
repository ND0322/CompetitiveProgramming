#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<long long> a(n);


        for(int i = 0; i < n; i++)cin >> a[i];

        long long x= 2;
       
        for(int i = 0; i <= 120; i++){
            set<int> s;

            for(int j = 0; j < n; j++){
                s.insert(a[j] % x);
                //cout << a[j]%(1<<i) << " ";
            }

            //cout << "\n";
            if(s.size() == 2){
                cout << x << "\n";
                break;
            }

            x<<=1;
        }
        
        
    }
}