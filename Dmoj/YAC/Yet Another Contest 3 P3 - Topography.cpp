#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

//take union of inc
//take union of dec
//both with line sweep
//check some stuff

int n, m, ans[MAXN];



vector<pair<int,int>> inc, de;

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int t,l,r; cin >> t >> l >> r;

        if(t == 1) inc.push_back({l,r});
        if(t == 2) de.push_back({l,r});
    }

    sort(inc.begin(), inc.end());
    sort(de.begin(), de.end());
    vector<pair<int,int>> a, b;


    int i = 0;

    while(i < inc.size()){
        int l = inc[i].first;
        int r = inc[i].second;

        while(i < inc.size() && inc[i+1].first <= r) r = max(r, inc[++i].second);

        a.push_back({l,r});
    }

    i = 0;

    while(i < de.size()){
        int l = de[i].first;
        int r = de[i].second;

        while(i < de.size() && de[i+1].first <= r) r = max(r, de[++i].second);
        b.push_back({l,r});
    }

    //bottleneck here

    for(auto [l,r] : a){
        for(auto [x,y] : b){
            if(x < r && l <= x){
                cout << "-1\n";
                return 0;
            }
        }
    }

    vector<pair<pair<int,int>,bool>> all;

    for(auto [l,r] : a) all.push_back({{l,r},0});
    for(auto [l,r] : b) all.push_back({{l,r},1});

    sort(all.begin(),all.end());

    for(auto range : all){
        int l = range.first.first;
        int r = range.first.second;

        if(!range.second){
            for(int i = l; i <= r; i++) ans[i] = l-i+1;
        }
        else{
            for(int i = r; i >= l; i--)
        }
    }
}
