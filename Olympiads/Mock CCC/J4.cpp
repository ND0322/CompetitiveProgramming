#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    string s; cin >> s;

    int cnt = 0;

    int sum = 0;

    for(char c: s){
        if(c == '*') cnt++;
        else sum += c-'a'+1;
    }

    if(sum + cnt > n){
        cout << "Impossible\n";
        return 0;
    }
    if(sum + 26 * cnt < n){
        cout << "Impossible\n";
        return 0;
    }

    string ans;

    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '*'){
            for(int j = 26; j >= 1; j--){
                if(n-sum-j >= cnt-1){
                    cnt--;
                    ans += (char)('a' + j - 1);
                    n -= j;
                    break;
                }
            }
        }
        else ans += s[i];
    }

    if(ans.size() != s.size()){
        cout << "Impossible\n";
        return 0;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
        


}