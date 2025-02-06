#include <bits/stdc++.h>
#include <iostream>
#include <deque>

using namespace std;

int main(){
    string s; cin >> s;

    bool side = s.size() & 1;

    deque<char> dq;

    for(char c : s) dq.push_back(c);

    string ans;
    while(dq.size()){
        if(!side){
            ans += dq.back();
            dq.pop_back();
        }
        else{
            ans += dq.front();
            dq.pop_front();
        }

        side = !side;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    
}