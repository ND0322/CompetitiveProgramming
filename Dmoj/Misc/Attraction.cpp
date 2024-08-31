#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int n, a, b;

/*
3 degrees
degree one is the original range
we add ceil(len/2) for these
for even we can push another thing with len/2 that is degree 2
for odd push another thing with len/2-1 with degree 3
for all degree 3 things we push another child with length 1 if length of me is odd
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> a >> b;

        multiset<pair<int,int>, greater<pair<int,int>>> ranges;

        vector<int> init;

        init.push_back(0);
        for(int i = 0; i < a; i++){
            int x; cin >> x;
            init.push_back(x);
        }

        init.push_back(n+1);    

        //0 to 1 and n to n+1 are special

        sort(init.begin(), init.end());

        

        int ans = 0;
        for(int i = 2; i < init.size()-1; i++) ranges.insert({ceil((init[i] - init[i-1]-1)/(double)2), (init[i] - init[i-1]-1) & 1});
        ranges.insert({init[1] - init[0]-1, 2});
        if(a) ranges.insert({init[a+1] - init[a]-1, 2});

        //for(auto [x,y] : ranges) cout << x << " " << y << "\n";
        

        while(b-- && ranges.size()){
            auto [x,deg] = *ranges.begin();

            //cout << x << " " << deg << "\n";
            if(deg <= 1){
                ans += x;
                ranges.erase(ranges.begin());
                if(deg == 1 && x > 1) ranges.insert({x-2, 3});
                if(deg == 0) ranges.insert({x, 2});
            }

            if(deg == 2){
                ans += x;
                ranges.erase(ranges.begin());
            }

            if(deg == 3){
                ans += x;
                ranges.erase(ranges.begin());
                ranges.insert({1, 2});
            }
        }

        cout << ans << "\n";
    }
    
}