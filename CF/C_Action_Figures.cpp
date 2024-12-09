#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

#define int long long


//its fine to delay everything to the last day
//greedy buy only the cheapest and most expensive currently
//run in reverse maybe 
//mark used nodes 
//we will never get not 1 things for free 
//keep a queue of fodder and of 1s 

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        set<int> fodder;
        set<int> ones;

        int ans = 0;

        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            if(c == '0') fodder.insert(i);
            else ones.insert(i);
        }

        for(int i = n; i >= 1; i--){
            if(ones.find(i) != ones.end()){
                if(fodder.size()){
                    ans += *fodder.rbegin();
                    fodder.erase(prev(fodder.end()));
                }
                else if(ones.size()){
                    ans += *ones.begin();
                    ones.erase(ones.begin());
                }
                else ans += i;

                ones.erase(i);
                    
                
            }      

            if(fodder.find(i) != fodder.end()){
                ans += i;
                fodder.erase(i);
            }      
        }



        cout << ans << "\n";

        
    }
}