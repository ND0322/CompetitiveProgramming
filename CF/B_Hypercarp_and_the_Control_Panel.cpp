#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    //sum of run lengths - 1
    //swapping reduces answer by at most 2

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<pair<int,int>> rl;
        
        rl.push_back({0,0});

        int i = 1;

        int tot = 0;

        while(i <= n){
            int l = i;

            while(i <= n && a[i] == a[l]) i++;

            rl.push_back({a[l], i-l});
            tot += i-l-1;
        }

        rl.push_back({0,0});

        if(rl.size() == 3){
            cout << "1\n";
            continue;
        }

        bool flag = 0;

        for(int i = 1; i < rl.size()-1; i++){
            if(rl[i].second >= 2 && rl[i+1].second >= 2) flag = 1;
        }

        if(flag){
            cout << n - tot + 2 << "\n";
            continue;
        }

        //singleton swaps

        flag = 0;
        for(int i = 0; i < rl.size()-2; i++){
            //cout << rl[i].second << " " << rl[i+2].second << " " << rl[i].first << " " << rl[i+2].first << "\n";
            if((rl[i].second >= 2 || rl[i+2].second >= 2) && rl[i].first != rl[i+2].first) flag = 1;
        }


        cout << n - tot + flag << "\n";


        
        


    

        
    }
}