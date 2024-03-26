#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 5e5+5;

int n;

map<int, vector<int>> freq;

int main(){
    cin >> n;

    for(int i = 1; i <= 2*n; i++){
        int x; cin >> x;

        freq[x].push_back(i);
    }

    vector<pair<int,int>> a;

    for(auto i : freq) a.push_back({i.second.size(), i.first});

    sort(a.begin(), a.end());

    int l = 0;
    int r = 0;
    int i = 0;
    int j = 0;

    while(l < a.size() && r < a.size()){
        
        while(i < a[l].second && j < a[r].second){
            cout << freq[a[l].first][i] << " " << freq[a[r].first][j] << "\n";
            i++;
            j++;
        }

        if(j == a[r].second) r++;
        if(i == a[l].second) l = r;
    }
}