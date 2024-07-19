#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 2e5+5;

int n, m;

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        string s; cin >> s;
        vector<char> ans(n);

        map<int,int> freq;
        for(int i = 1; i <= m; i++){
            int x; cin >> x;
            freq[x-1]++;
        }

        int l = 0;
        int r = 0;

        string b; cin >> b;

        sort(b.begin(), b.end());



        for(int i = 0; i < n; i++){
            if(freq.find(i) == freq.end()){
                ans[i] = s[i];
                continue;
            }

            r -= freq[i];
            ans[i] = b[l++];
        }

        for(char c : ans) cout << c;
        cout << "\n";



        
    }
}

