#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

//try to build 1 to k in order
//if this i is not the one we want and its the last occurence of it we have to take it

const int MAXN = 2e5+5;

int n,k, a[MAXN], freq[MAXN], last[MAXN];

bool in[MAXN];


int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        last[a[i]] = i;
    }

    vector<pair<int,int>> ans;

    for(int i = 0; i < n; i++){
        if(!in[a[i]]){
            ans.push_back({a[i],i});
            continue;
        }

        if(ans.back().second != last[ans.back().first] && ans.back().first > a[i]){
            in[ans.back().first] = 0;
            ans.pop_back();
            ans.push_back({a[i], i});
            in[a[i]] = 1;
        }
    }

    for(pair<int,int> i : ans) cout << i.first << "\n";


   

    

    
}