#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

/*
only the last cell changes

the next colored cell only increases

so we can just precalculate all white cells after the last one + any As that mightve happend

*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        vector<bool> opt(m+1);

        set<int> marked;
        set<pair<int,int>> intervals;
        set<int> tmp;

        for(int i = 1; i <= n; i++){
            char c; cin >> c;

            opt[i] = (c == 'A');
        }

        for(int i = 1; i <= m; i++){
            int x; cin >> x;
            marked.insert(x);
        }

        for(int i : marked){
            if(tmp.find(i) != tmp.end()) continue;
            pair<int,int> res = {i, 1};

            
            while(marked.find(i+1) != marked.end()){
                i++;
                res.second++;
                tmp.insert(i);
            }

            intervals.insert(res);
            for(int j = 1; j < res.second; j++) intervals.insert({res.first+j, --res.second});
        }


        int pos = 1;

        for(int i = 1; i <= n; i++){
            if(opt[i]) pos++;
            else{
                auto it = intervals.lower_bound({pos, -1});
                if(it == intervals.end()) pos++;
                else{
                    auto [x,y] = * it;


                    if(pos+1 < x || pos+1 > x+y) pos++;
                    else pos = x + y;
                }
            }   
            
            if(marked.find(pos) != marked.end()) continue;

            marked.insert(pos);

            if(!opt[i]){
                auto it = intervals.lower_bound({pos, -1});
                if(it == intervals.end()) pos++;
                else{
                    auto [x,y] = * it;


                    if(pos+1 < x || pos+1 > x+y) pos++;
                    else pos = x + y;
                }
            }
        }

        cout << marked.size() << "\n";

        for(int i : marked) cout << i << " ";

        cout << "\n";








    }
}