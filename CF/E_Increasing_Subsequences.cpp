#include <bits/stdc++.h>
#include <iostream>

#define int long long

using namespace std;

long long l,r;

vector<int> ans;

void dac(int x){
    if(x == 1) return;
    if(x & 1){
        dac(x-1);
        l--;
        ans.push_back(l);
    }
    else{
        dac(x>>1);
        r++;
        ans.push_back(r);
    }
}

int32_t main(){
    //have a reverse sorted part and sorted part
    //sum of sorted part will equal
    
    //2^i - 1
    //where i is the length

    int tt; cin >> tt;

    while(tt--){
        long long x; cin >> x;

        ans.clear();

        dac(x);

        cout << ans.size() << "\n";

        for(int i : ans) cout << i << " ";
        cout << "\n";

        

        






    }


    

    
}


/*
try to solve a quickly
give b like 15 minutes then read c if no progress
dont tilt 
integer overflow and upper bound bad
c is easier than you think
*/