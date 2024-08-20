#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN];

map<int,int> freq;



int main(){
    cin >> n;

    pair<int,int> mx = {0,0};

    for(int i = 1; i <= n; i++){
        cin >> a[i];

        if(mx.first == a[i]) mx.second++;
        else mx = {a[i], 1};

        freq[a[i]]++;
    }

    if(mx.second & 1){
        cout << "Conan\n";
        return 0;
    }

    for(auto i : freq){
        if(i.second & 1){
            cout << "Conan\n";
            return 0;
        }
    }

    cout << "Agasa\n";

    
    

   

}