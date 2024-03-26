#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 20;

int n,k;

long long fact[MAXN], freq[30];

int main(){
    cin >> n >> k;
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;

    string s; cin >> s;

    for(int i = 1; i <= n; i++){
        if(s[i-1] == '*') continue;
        
        freq[s[i-1]-'a'+1]++;
    }

    if(!k){
        long long ans = fact[n];

        long long div = 1;

        for(int i = 1; i <= 26; i++) div *= fact[freq[i]];

        cout << ans/div << "\n";
        return 0;
    }

    if(k == 1){
        long long ans = 0;

        for(int i = 1; i <= 26; i++){

            long long tot = fact[n];
            long long div = 1;
            for(int j = 1; j <= 26; j++){
                if(j == i) continue;
                div *= fact[freq[j]];
            }

            div *= fact[freq[i]+1];

            ans += tot/div;
        }

        cout << ans << "\n";
        return 0;
    }

    long long ans = 0;

    for(int i = 1; i <= 26; i++){
        for(int j = i; j <= 26; j++){
            long long tot = fact[n];
            long long div = 1;

            for(int k = 1; k <= 26; k++) div *= fact[freq[k] + (i == k) + (j == k)];

            ans += tot/div;
        }
    }

    cout << ans << "\n";
}