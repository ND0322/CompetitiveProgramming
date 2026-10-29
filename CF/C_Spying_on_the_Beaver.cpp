#include <bits/stdc++.h>
#include <iostream>

/*
upper bounded by m-1
*/

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 1; i <= n-1; i++){
            int x; cin >> x;
        }

        int k; cin >> k;

        cout << k-1 << " ";


        set<int> s;

        for(int i = 1; i <= k; i++){
            int x; cin >> x;

            s.insert(x);
        }

        if(s.find(1) == s.end()) s.erase(s.begin());
        else s.erase(1);

        for(int i : s) cout << i << " ";

        
            
        cout << "\n";
    }
}