#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 505;

int n, a[MAXN][MAXN], parents[MAXN*MAXN], cnt, ans[MAXN*MAXN], rt[MAXN*MAXN];

map<int,int> mp;

//sort by a[i] increasing
//what if two a[i] are equal
//this means that all either 3 or 4 nodes share that lca 
//the smallest a[i] will have leaf children
//start with only the given leaf nodes
//for every new thing added we will make it the parent of the roots of the leafs 
//1,3, 2 root of 1 and 2 is a child of this new node as well as root of 3

/*
      5
     / \  
    4   3
   / \
  1   2
*/


int find(int x){
    while(x != parents[x]) x = parents[x];
    return x;
}



int main(){
    cin >> n;


    for(int i = 1; i <= n*n; i++){
        parents[i] = i;
        rt[i] = i;
    }
    cnt = n+1;

    vector<pair<int,pair<int,int>>> s;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;

            
            s.push_back({x, {i,j}});
        }
    }

    sort(s.begin(), s.end());

    for(auto i : s){
        int v = i.first;
        auto [x,y] = i.second;

        if(x == y){
            ans[x] = v;
            continue;
        }

        if(ans[find(x)] != v && ans[find(y)] != v){
            ans[cnt] = v;
            parents[find(x)] = cnt;
            parents[find(y)] = cnt;
            mp[v] = cnt++;
        }
        else{
            if(ans[find(y)] == v) swap(x,y);
            parents[find(y)] = find(x);
        }
        


    }

    cout << cnt-1 << "\n";
    for(int i = 1; i < cnt; i++) cout << ans[i] << " ";
    cout << "\n";
    cout << cnt-1 << "\n";
    for(int i = 1; i < cnt-1; i++) cout << i << " " << parents[i] << "\n";
    



     
}