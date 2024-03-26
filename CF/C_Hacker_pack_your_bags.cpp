#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 2e5+5;

int n, x;

map<int,vector<int>> a,b, pmax, smax;
map<int,vector<pair<pair<int,int>,int>>> ranges;
vector<pair<pair<int,int>,int>> inp; 

/*
seperate into lengths and do bs + prefix max/suffix max
*/

int main(){
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        int l,r,c; cin >> l >> r >> c;

        ranges[r-l+1].push_back({{l,r},c});
        inp.push_back({{l,r},c});
    }

    for(auto i : ranges){
        sort(i.second.begin(), i.second.end());

        for(auto j : i.second){
            a[i.first].push_back(j.first.second);
            b[i.first].push_back(j.first.first);
        }

        pmax[i.first] = vector<int>(i.second.size()+1);
        smax[i.first] = vector<int>(i.second.size()+1);

        pmax[i.first][0] = i.second[0].second;
        for(int j = 1; j < i.second.size(); j++) pmax[i.first][j] = min(pmax[i.first][j-1], i.second[j].second);
        smax[i.first][i.second.size()-1] = i.second[i.second.size()-1].second;
        for(int j = i.second.size()-2; j >= 0; j--) smax[i.first][j] = min(smax[i.first][j+1], i.second[j].second);
    }


    long long ans = 1e18;
    for(auto range : inp){
        int l = range.first.first;
        int r = range.first.second;
        int c = range.second;

        if(a.find(x-r+l-1) == a.end()) continue;
        int lo = 0;
        int hi = a[x-r+l-1].size()-1;
        int res = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(a[x-r+l-1][mid] < l){
                res = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        

        if(res != -1) ans = min(ans, (long long)pmax[x-r+l-1][res] + c);
            
        

        lo = 0;
        hi = b[x-r+l-1].size()-1;
        res = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(b[x-r+l-1][mid] > r){
                res = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        if(res != -1) ans = min(ans, (long long)smax[x-r+l-1][res] + c);
           
    }

    cout << (ans < 1e18 ? ans : -1) << "\n";
    

}