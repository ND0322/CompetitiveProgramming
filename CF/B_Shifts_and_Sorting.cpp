#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//process right to left and do the basically swaps

const int MAXN = 2e5+5;

bool a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        
        string s; cin >> s;

        int n = s.size();

        int cnt = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0' && cnt) ans += (cnt+1);
            if(s[i] == '1') cnt++;
        }

        cout << ans << "\n";
    }
}