#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(is_sorted(a.begin(), a.end())){
            for(int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << "\n";
            continue;
        }

        vector<int> b;

        priority_queue<int, vector<int>, greater<int>> pq;
        int mn = 1e9;
        for(int i = n; i >= 1; i--){
            if(a[i] > mn){
                pq.push(a[i]+1);
                continue;
            }

            mn = min(mn, a[i]);

            b.push_back(a[i]);
        }

        reverse(b.begin(), b.end());


        vector<int> c;

        for(int i = 0; i < b.size(); i++){
            if(b[i] > pq.top()){
                pq.push(b[i]+1);
                continue;
            }

            c.push_back(b[i]);
        }

        while(pq.size()){
            c.push_back(pq.top());
            pq.pop();
        }

        for(int i : c) cout << i << " ";
        cout << "\n";

    }
}

//resulting answer will always be sorted?
//each thing will be moved at most once
//things that have smaller things on the right 
//probably fast enough to straight up implement greedily with pq
//only the suffix could be bad
//bsearch on the suffix 
//we will be left with a sorted suffix after the first removal 
//all things bigger than minimum in pq will be moved
//so it will be done after one comparison and the rest will be pq
