#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 1005;

int n;

pair<int,int> a[MAXN];

map<int,map<int,bool>> is;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;

        is[a[i].first][a[i].second] = 1;
    }

    
}
