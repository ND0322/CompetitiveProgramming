#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> freq(n+1);

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(x >= n) continue;
            freq[x]++;
        }


        int ans = 0;
        for(int i = 0; i <= n; i++){
            if(!freq[i]){
                ans = i;
                break;
            }

            if(i+k < n) freq[i+k] += freq[i] - 1;
        }

        cout << ans << "\n";
    }
}