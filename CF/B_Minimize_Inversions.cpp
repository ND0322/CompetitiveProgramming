#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<pair<int,pair<int,int>>> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i].second.first;
            a[i].first += a[i].second.first;
        }

        for(int i = 0; i < n; i++){
            cin >> a[i].second.second;
            a[i].first += a[i].second.second;
        }
        
        sort(a.begin(), a.end());

        for(int i = 0; i < n;i ++) cout << a[i].second.first << " ";
        cout << "\n";
        for(int i = 0; i < n; i++) cout << a[i].second.second << " ";
        cout << "\n";
    }
}