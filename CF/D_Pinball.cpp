#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

#define int long long

int n;

string s;

//thing bounces back and forth until it gets out
//it will repeatedly extend l and r by 1
//sliding window?
//>>><<<
//this is easy
//starting dir only matters if l and r are equal for adding the final interval




int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;
        cin >> s;
        vector<int> l(n), r(n);
        for(int i = 1; i < n; i++) l[i] = l[i-1] + (s[i-1] == '>');
        for(int i = n-2; i >= 0; i--) r[i] = r[i+1] + (s[i+1] == '<');
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '<') {
                if(l[i] > r[i]) l[i] = r[i] + 1;
                else r[i] = l[i];
            }
            else {
                if(r[i] > l[i]) r[i] = l[i] + 1;
                else l[i] = r[i];
            }
        }
    vector<int> res(n);
    vector<int> pref(1);
    for(int i = 0; i < n; i++) {
        res[i] += 2 * (i * l[i] - (pref.back() - pref[(int)pref.size() - 1 - l[i]]));
        if(s[i] == '>') pref.push_back(pref.back() + i);
    }
    vector<int> suf(1);
    for(int i = n - 1; i >= 0; i--) {
        res[i] += 2 * (-i * r[i] + (suf.back() - suf[(int)suf.size() - 1 - r[i]]));
        if(s[i] == '<') suf.push_back(suf.back()+ i);
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '<') {
            if(l[i] > r[i]) res[i] += n - i;
            else res[i] += i + 1;
        }
        else{
            if(r[i] > l[i]) res[i] += i+1;
            else res[i] += n-i;
        }
      }
    
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << "\n";
    
    





    }
}