#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long


/*
for each ai

iterate through all m such that m <= n

a[i+m] = m / a[i]
*/
int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];


        int ans = 0;

        set<int> s;

        for(int i = 1; i <= n; i++){
            if(a[i] * a[i] >= n){
                for(int j = a[i]; i + j <= n; j += a[i]){

                    if(a[i + j] == j / a[i]) ans++;
                }
            }
            else s.insert(a[i]);
        }


        //a[i] * a[j] = j-i
        //d = a[i] * a[j]
        

        for(int x : s){
            for(int i = 1; i <= n; i++){
                int d = x * a[i];

                if((i-d >= 1) && a[i-d] == x){
                    ans++;
                }
            }
        }   

        cout << ans << "\n";
    }
}