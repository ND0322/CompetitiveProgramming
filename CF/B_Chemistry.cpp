#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int n,k;

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        string s; cin >> s;

        if(n == k+1){
            cout << "YES\n";
            continue;
    
        }

        unordered_map<char,int> freq;

        for(char c: s){
            if(freq.find(c) == freq.end()) freq[c]=1;
            else freq[c]++;
        }

        
        int ans = 0;
        int cnt = 0;
        bool check = false;

        for(auto i: freq){
            if(i.second & 1){

                if(!check && (n-k)&1) check = true;
                else{
                    ans++;
                    freq[i.first]--;
                }
                
            }
        }

        
        if(ans > k){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

      

       

        

       


    }
    
}