#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    vector<int> a = {1,2,3,4,5};
    vector<int> b;

    for(int i : a) b.push_back(i);
    int bad = 4;

    for(int i : a) cout << i << " ";
    cout << "\n";

    a.clear();

    for(int i = 0; i < 5; i++){
        if(i == bad) continue;
        a.push_back(b[i]);
        
    }

    for(int i : a) cout << i << " ";
    cout << "\n";
}

