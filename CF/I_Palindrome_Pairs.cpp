#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int cnt[1<<26];

int main(){
    int n; cin >> n;

    for(int i= 0; i < n; i++){
        string s; cin >> s;

        bool p[26];

        memset(p, 0, sizeof(p));

        for(int j = 0; j < s.size(); j++) p[s[j] - 'a']^=1;

        int mask = 0;

        for(int j = 0; j < 26;j++) mask += (p[j] << j);
        cnt[mask]++;
    }

    long long ans = 0;

    for(int i = 0; i < (1<<26); i++){
        if(i == (i&((1<<27)-1))) ans += cnt[i] * (cnt[i]-1);
        else ans += cnt[i] * cnt[i&((1<<27)-1)];
        
    }

    cout << ans/2 << "\n";
}

