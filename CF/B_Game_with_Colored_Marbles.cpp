#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//frequency array
//the best that can happen is one of each

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> freq(n+1);

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            freq[x]++;
        }

        sort(freq)
    }
}