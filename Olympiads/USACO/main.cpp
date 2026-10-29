#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 1e6+5;

int n,k;

string s, t; 

vector<int> pos1, pos2;

int main(){
    cin >> n >> k;

    cin >> s >> t;

    for(int i = 0; i < n; i++){
        if(s[i] - '1') pos1.push_back(i);
        if(t[i] - '1') pos2.push_back(i);
    }

    long long ans = 0;

    for(int i = 0; i < pos1.size(); i++) ans += abs(pos1[i] - pos2[i]);

    cout << ans << "\n";


}