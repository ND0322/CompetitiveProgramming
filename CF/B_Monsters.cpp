#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k; cin >> n >> k;

       
        vector<pii> a;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            if(x%k == 0){
                cout << i << " ";
                continue;
            } 

            a.push_back({-x%k,i});
        }

        sort(a.begin(),a.end());


        for(pii i : a){
            cout << i.second << " ";
        }

        cout << "\n";

        

        
        


    }
}