#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
iterate through all run sizes and check that the number of runs and shit matches the mod
*/


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        set<int> ans;


        vector<int> a(n+2);

        int sz = 1;

        multiset<int> todo;


        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            if(a[i] == a[i+1]) sz++;
            else{
                todo.insert(sz);
                sz = 1;
            }
            
        }

        int left = n;

        if(left <= k && (k-left) % todo.size() == 0) ans.insert(todo.size());
        for(int i = 1; todo.size(); i++){
            left -= todo.size();
            while(todo.size() && *todo.begin() <= i) todo.erase(todo.begin());
            if(todo.empty()) break;
            if(k < left) continue;
            //for(int l : todo) cout << l << " ";
            //cout << "\n";
            if((k-left) % todo.size() == 0) ans.insert(todo.size());
        }


        cout << ans.size() << "\n";

        


    }
}