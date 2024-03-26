#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m, q, freq[26][2];

bool poss[26][26];

string s,t;

void solve(){
    string qu; cin >> qu;

    for(char c : qu){
        if(freq[c-'a'][0] != freq[c-'a'][1]){
            cout << "N";
            return;
        }
    }

    for(int i = 0; i < qu.size(); i++){
        for(int j = i+1; j < qu.size(); j++){
            if(!poss[qu[i] - 'a'][qu[j] - 'a']){
                cout << "N";
                return;
            }
        }
    }

    cout << "Y";
}

int main(){
    cin >> s >> t;

    n = s.size();
    m = t.size();

    for(int i = 0; i < n; i++) freq[s[i]-'a'][0]++;
    for(int i = 0; i < m; i++) freq[t[i]-'a'][1]++;

    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 18; j++){
            //check if the pair is possible
            //if not the whole dude aint

            string l,r;

            for(int k = 0; k < n; k++){
                if(s[k]-'a' == i || s[k]-'a' == j) l += s[k];
            }

            for(int k = 0; k < m; k++){
                if(t[k]-'a' == i || t[k]-'a' == j) r += t[k];
            }

            poss[i][j] = (l==r);
        }
    }

    cin >> q;

    while(q--) solve();

    cout << "\n";
    


}