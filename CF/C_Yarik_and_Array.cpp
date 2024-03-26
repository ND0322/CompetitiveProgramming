#include <bits/stdc++.h>  
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        int ans = -1e9;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += a[i];

            if(i) if((a[i]&1) == (a[i-1]&1)) sum=a[i];

            ans = max(ans,sum);
            if(sum < 0)sum = 0;
        }

        

        cout << ans << "\n";
    }
}