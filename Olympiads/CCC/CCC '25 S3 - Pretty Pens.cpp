#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, m, q, col[MAXN], p[MAXN];

multiset<int> s[MAXN];


//literally just sets nd logic
//greedily change the pen color
//how?
//take second best and change it to the worst color
//we need to store second bests 
//need to precomp the answer

int32_t main(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        cin >> col[i] >> p[i];

        s[col[i]].insert(-p[i]);
    }



    long long sm = 0;
    
    multiset<int> sec;
    multiset<int> worst;

    for(int i = 1; i <= m; i++){
        if(!s[i].size()){
            worst.insert(0);
            continue;
        }

        sm += -*s[i].begin();

        worst.insert(*s[i].begin());

        if(s[i].size() > 1) sec.insert(*next(s[i].begin()));
        
    }


    
    cout << sm + max((sec.size() ? -*sec.begin() : 0) + *worst.rbegin(), 0LL) << "\n";

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int i, c; cin >> i >> c;

            //recalc best and second best for both original and new

            worst.erase(worst.find(*s[col[i]].begin()));
            if(s[col[i]].size() > 1) sec.erase(sec.find(*next(s[col[i]].begin())));

            sm -= -*s[col[i]].begin();

            
            s[col[i]].erase(s[col[i]].find(-p[i]));

            if(!s[col[i]].size()){
                worst.insert(0);
            }
            else{
                sm += -*s[col[i]].begin();
            

                worst.insert(*s[col[i]].begin());

                if(s[col[i]].size() > 1) sec.insert(*next(s[col[i]].begin()));
            }

            col[i] = c;
            worst.erase(worst.find(*s[col[i]].begin()));
            if(s[col[i]].size() > 1) sec.erase(sec.find(*next(s[col[i]].begin())));
            
            sm -= -*s[col[i]].begin();



            s[col[i]].insert(-p[i]);

            if(!s[col[i]].size()) worst.insert(0);
            else{
                sm += -*s[col[i]].begin();

                worst.insert(*s[col[i]].begin());

                if(s[col[i]].size() > 1) sec.insert(*next(s[col[i]].begin()));
            }

            cout << sm + max((sec.size() ? -*sec.begin() : 0) + *worst.rbegin(), 0LL) << "\n";
        }

        if(t == 2){
            int i,c; cin >> i >> c;

            //recalc best and second best for both original and new



            worst.erase(worst.find((*s[col[i]].begin())));
            if(s[col[i]].size() > 1) sec.erase(sec.find(*next(s[col[i]].begin())));
            sm -= -*s[col[i]].begin();
            s[col[i]].erase(s[col[i]].find(-p[i]));

            p[i] = c;
            s[col[i]].insert(-p[i]);
            
            sm += -*s[col[i]].begin();

            worst.insert(*s[col[i]].begin());

            if(s[col[i]].size() > 1) sec.insert(*next(s[col[i]].begin()));

        
            cout << sm + max((sec.size() ? -*sec.begin() : 0) + *worst.rbegin(), 0LL) << "\n";


        }
    }
    


}