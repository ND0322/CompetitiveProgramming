#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    string s; cin >> s;

    string ans;

    for(char c:s){
        ans += c;

        if(ans.size() >= 3 && ans[ans.size() - 1] == 'C' && ans[ans.size()-2] == 'B' && ans[ans.size()-3] == 'A') ans.erase(ans.end()-3, ans.end());

    }
    cout << ans << "\n";
}