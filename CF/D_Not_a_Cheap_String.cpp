#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int w; cin >> w;

        vector<int>psa(s.size()+1);

        string t = s;
        sort(t.rbegin(), t.rend());

        for(int i = 1; i <= t.size(); i++){
            psa[i] = t[i-1]-'a'+1;
            psa[i] += psa[i-1];
        }

        map<char,int> freq;


        //1 + 2 + 3 + 1
        
        for(int i = 0; i <= t.size(); i++){
            freq[t[i-1]]++;
            if(psa[t.size()] - psa[i] <= w) break;
        }

        string ans;

        for(char c:s){
            if(!freq[c]) ans += c;
            else freq[c]--;
        }

        cout << ans << "\n";




    }
}