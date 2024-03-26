#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>


using namespace std;



const int MAXN = 3e5+5;

int n, k, a[MAXN];

multiset<long long> s;
long long t[MAXN];

map<long long, vector<int>> mp;
set<long long> done;


bool vis[MAXN];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    //check which interviewers can possibly be free at the end

    for(int i = 1; i <= k; i++) s.insert(a[i]);
    
    

    int i = k+1;

    while(i <= n){
        long long x = *s.begin();

        s.erase(s.begin());
        t[i] = x;
        s.insert(a[i++] + x);
    }



    cout << (*s.begin())<< "\n";

    for(int i = 1; i <= n; i++) mp[a[i] + t[i]].push_back(i);
    queue<int> q;

    vis[n+1] = 1;
    t[n+1] = (*s.begin());

    q.push(n+1);

    while(!q.empty()){
        int node = q.front();

        q.pop();
        if(node <= k) continue;

        if(done.find(t[node]) != done.end()) continue;

        for(int i : mp[t[node]]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    for(int i = 1; i <= k; i++) cout << vis[i];

}