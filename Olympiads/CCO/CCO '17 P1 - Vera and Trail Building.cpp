#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int a[5005];

vector<int> save;
int main(){
    int k; cin >> k;

    a[2] = 1;
    for(int i = 3; i <= 5000; i++) a[i] = a[i-1] + i-1;

    int cnt = 0;
    for(int i = 5000; i >= 2; i--){
        while(k >= a[i]){
            save.push_back(i);
            k-=a[i];
            cnt += i;
        }
    }

    vector<pair<int,int>> edges;

    for(int i = 2; i <= cnt; i++) edges.push_back({i,i-1});
    
    cnt = 0;
    for(int i : save){
        edges.push_back({cnt+i, cnt+1});
        cnt+=i;
    }

    cout << cnt << " " << edges.size() << "\n";

    for(pair<int,int> p : edges) cout <<p.first << " " << p.second << "\n";




}