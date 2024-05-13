#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 3e5+5;

int n, a[MAXN], b[MAXN];

set<int> ord, cand, nxt, tmp;

//maintain a list of candidates for each round and propagate the neighbours
//keep the order right by deleting at the end of the roud

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        ord.clear();
        cand.clear();
        nxt.clear();
        tmp.clear();

        for(int i = 1; i <= n; i++){
            ord.insert(i);
            cand.insert(i);
        }

        for(int j = 1; j <= n; j++){
            int cnt = 0;

            
            for(int i : cand){
                if(ord.find(i) == ord.end()) continue;


                int l = 0;
                int r = 0;

                auto it = ord.find(i);

                if(next(it) != ord.end()){
                    it++;
                    r = a[*it];
                }

                it = ord.find(i);

                if(it != ord.begin()){
                    it--;
                    l = a[*it];
                }

                //cout << j << " " << i << " " << l << " " << r << "\n";

                if(l+r > b[i]){
                    tmp.insert(i);
                    cnt++;
                    if(next(ord.find(i)) != ord.end()) nxt.insert(*next(ord.find(i)));
                    if(ord.find(i) != ord.begin()) nxt.insert(*prev(ord.find(i)));
                }
            }

            
            cout << cnt << " ";
            for(int i : tmp) ord.erase(i);   
            tmp.clear();
            cand = nxt;
            nxt.clear();
        }

        cout << "\n";
    }
}