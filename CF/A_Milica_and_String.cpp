#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

        string s; cin >> s;

        vector<int> psa(1);

        for(int i = 1; i <= n; i++) psa.push_back(psa[i-1] + (s[i-1] == 'B'));

        

        if(psa[n] == k){
            cout << "0\n";
            continue;
        } 


        if(psa[n] > k){
            
            for(int i = 1; i <= n; i++){
                if(psa[i] == psa[n]-k){
                    cout << 1 << "\n";
                    cout << i << " A\n";
                    break;
                }
            }
        }
        else{
            for(int i = 1; i <= n; i++){
                if(i-psa[i] == k-psa[n]){
                    cout << 1 << "\n";
                    cout << i << " B\n";
                    break;
                }
            }
        }
        
    }
}