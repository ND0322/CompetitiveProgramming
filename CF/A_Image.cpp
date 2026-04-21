#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    //more than 2 of one color we should convert to that color

    int tt; cin >> tt;

    while(tt--){
        map<int,int> freq;

        for(int i = 0; i < 4;i ++){
            char c; cin >> c;

            freq[c - 'a']++;
        }

        vector<int> a;
        for(auto i : freq) a.push_back(i.first);

        if(a.size() == 4){
            cout << "3\n";
            continue;
        }

        if(a.size() == 3){
            cout << "2\n";
            continue;
        }

        if(a.size() == 1){
            cout << "0\n";
            continue;
        }

        if(a[0] == 2){
            cout << "1\n";
            continue;
        }

        cout << "1\n";
        
    }



}