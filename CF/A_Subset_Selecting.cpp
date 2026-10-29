#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> freq(n+2);

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            freq[x]++;
        }

        int extra = 0;
        for(int i = 0; i <= n+1; i++){

            if(!freq[i]){
                cout << i << "\n";
                break;
            }

            freq[i]+= extra;
            if(freq[i] < k){
                cout << i << "\n";
                break;
            }

            extra = freq[i] - k;            
        }
    }
}