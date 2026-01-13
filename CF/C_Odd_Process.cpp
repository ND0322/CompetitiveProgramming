#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
start with odd and repeatedly take evens 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        priority_queue<int> evens;
        vector<int> odds;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(x & 1) odds.push_back(x);
            else evens.push(x);
        }


        sort(odds.rbegin(), odds.rend());

        if(odds.empty()){
            for(int i = 1; i <= n; i++) cout << "0 ";
            cout << "\n";
            continue;
        }

        //what if there are 2 odds

        int sm = odds[0];
        bool flag = 1;
        for(int i = 1; i <= n; i++){
            if(evens.empty()){
                flag ^= 1;

                if(flag) cout << sm - odds[odds.size()-1] - odds[odds.size()-2] << " ";
                else cout << sm << " ";
            }
            else{
                cout << sm << " ";
                sm += evens.top();
                evens.pop();
            }
        }

        cout << "\n";


        


    }
}