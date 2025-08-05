#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<pair<pair<int,int>,int>> ranges;

        for(int i = 1; i <= n; i++){
            int x,y; cin >> x >> y;

            ranges.push_back({{x,y}, i});
        }

        //deal with complete containments at the start, union the ranges and kill useless ones

        vector<int> good;

        for(auto [ballsack,nutsack] : ranges){
            
            auto [x,y] = ballsack;

            bool flag = 1;
            for(auto [a,b] : ranges){
                if((a.first <= x && a.second >= y) && !(a.first == x && a.second == y)){
                    flag = 0;
                    break;
                }
            }

            if(flag)good.push_back(nutsack);
        }

        cout << (int)good.size() << "\n";
        for(int i : good) cout << i << " ";
        cout << "\n";


    }
}