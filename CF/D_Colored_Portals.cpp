#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, q;

map<char,map<char,set<int>>> mp;
string col[MAXN];

//answer is either one step or two steps


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> q;

        mp.clear();

        for(int i = 1; i <= n; i++){
            cin >> col[i];

            mp[col[i][0]][col[i][1]].insert(i);
        }

        //color 1 is strictly less than color 2

        while(q--){
            int x,y; cin >> x >> y;

            if(x > y) swap(x,y);

            if(col[x][0] == col[y][0] || col[x][1] == col[y][0] || col[x][1] == col[y][1]){
                cout << y-x << "\n";
                continue;
            }

            int ans = 1e9;

            //check max less than x, anything between the two and min greater than y

            for(int i = 0; i < 2; i++){
                for(int j =0; j < 2; j++){
                    auto it = mp[col[x][i]][col[y][j]].lower_bound(x);
                    if(it != mp[col[x][i]][col[y][j]].end()) ans = min(ans, abs(*it - x) + abs(y - *it));
                    

                    if(it != mp[col[x][i]][col[y][j]].begin()){
                        it--;
                        ans = min(ans, abs(*it - x) + abs(y - *it));
                    }

                    it = mp[col[y][j]][col[x][i]].lower_bound(x);

                   
                    if(it != mp[col[y][j]][col[x][i]].end()) ans = min(ans, abs(*it - x) + abs(y - *it));
                    

                    if(it != mp[col[y][j]][col[x][i]].begin()){
                        it--;
                        ans = min(ans, abs(*it - x) + abs(y - *it));
                    }
                }
            }

            cout << (ans == 1e9 ? -1 : ans) << "\n";



        }
    }
}